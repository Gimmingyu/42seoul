/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:19:04 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:19:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "libft.h"

/*
 ** Define binary value of each flag
*/

enum
{
	LEFT_JUST = 0b10000,
	SIGN = 0b01000,
	SPACE = 0b00100,
	ZERO = 0b00010,
	SHARP = 0b00001
};

/*
 ** Define LEN value
*/

# define LEN	"hh ll l L h"

/*
 ** Define TYPES value
*/
# define TYPES "scpdiouxXf%"

/*
 ** Argument structure
*/

typedef struct				s_arg
{
	int						flags;
	int						min_width;
	int						precision;
	char					*len;
	char					arg_type;
	char					*print;
	int						print_size;
	char					*old_print;
	int						old_print_size;
}							t_arg;

typedef union				u_floatbits
{
	long double				d;
	struct
	{
		unsigned long long	m:64;
		unsigned int		expo:15;
		unsigned int		sign:1;
		unsigned long		empty:16;
	}						bits;
}							t_floatbits;

int							ft_printf(const char *str, ...);
int							ft_parsing(const char *str, t_arg **arg);
int							ft_dis(t_arg *arg, va_list ap);

/*
 ** Return size of read value otherwise or 0 if there is an error
*/

int							ft_parse_flag(const char *str, t_arg *arg);
int							ft_parse_width(const char *str, t_arg *arg);
int							ft_parse_precision(const char *str, t_arg *arg);
int							ft_parse_len(const char *str, t_arg *arg);
int							ft_parse_type(const char *str, t_arg *arg);
int							ft_addflag(t_arg *arg, int flag);
int							(*g_ft_get_type(char c))(va_list ap, t_arg *arg);

/*
 ** Return number of type => 1 or 0 if there is an error
*/

int							ft_type_string(va_list ap, t_arg *arg);
int							ft_type_char(va_list ap, t_arg *arg);
int							ft_type_pointer(va_list ap, t_arg *arg);
int							ft_type_int(va_list ap, t_arg *arg);
int							ft_get_sign(t_arg *arg, int sign_neg);
int							ft_unsigned(va_list ap, t_arg *arg, int base);
int							ft_type_octal(va_list ap, t_arg *arg);
int							ft_type_unsigned(va_list ap, t_arg *arg);
int							ft_type_hexmin(va_list ap, t_arg *arg);
int							ft_type_hexmaj(va_list ap, t_arg *arg);
int							ft_sharp(t_arg *arg);
int							ft_type_float(va_list ap, t_arg *arg);
char						*ft_ftoa(double d, int size);
int							ft_type_percent(va_list ap, t_arg *arg);
int							ft_sp_u(t_arg *arg);
int							ft_sp_wu_0(t_arg *arg);
int							ft_sp_ws(t_arg *arg);
int							ft_sp_sup(t_arg *arg, int i);
int							ft_sp_lsp(t_arg *arg);
int							ft_space_d(t_arg *arg, int sign_neg);
long double					ft_get_mant(unsigned long long nb);
char						*ft_calc_mant(char **tab_mant, t_arg *airg, int i);
int							ft_spec_zero_d(t_arg *arg);
int							ft_spec_zero_d_flag(t_arg *arg);
int							ft_check_zero_d(t_arg *arg);
int							ft_spec_zero_u(t_arg *arg);
char						*ft_bin_mant(unsigned long long i, int size);
char						*ft_calc_real_neg(char *mant, int exp_d);
char						*ft_calc_real_pos(char *mant, int exp_d);
int							ft_sign_float(t_arg *arg, int sign);
int							ft_space_float(t_arg *arg, int sign, int i);
char						*ft_inf_nan(unsigned int expo, char *mantissa
		, t_arg *arg);
char						*ft_mant(char *mantissa, t_arg *arg, int i);
int							ft_check_round(t_arg *arg);
int							ft_sharpf(t_arg *arg);
int							ft_width_f(t_arg *arg, int sign);
int							ft_fl_ok(t_arg *arg, char *mantissa
		, t_floatbits *fl);
int							ft_width_inf_nan(t_arg *arg, int sign);
void						ft_free_arg(char **tab_mant, char *str);

#endif
