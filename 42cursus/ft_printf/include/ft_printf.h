/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:39:20 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:05:38 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DOUBLE_FRAC_MAN_SIZE 768
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"
# define DIGIT "0123456789"
# define OCTAL "01234567"

# include <stdarg.h>
# include <unistd.h>
# include <ctype.h>
# include <wchar.h>
# include <math.h>
# include <stdint.h>
# include "libft.h"

typedef struct	s_form
{
	va_list	va_para;
	int		result;
	int		width;
	int		precision;
	char	specifier;
	char	hhll;
	char	ladjust;
	char	sign;
	char	*padc;
	char	hash_flag;
	size_t	pre_width;
	size_t	put_width;
}				t_form;

typedef struct	s_fraction
{
	char		sign;
	int			exp;
	int			man_len;
	char		man[DOUBLE_FRAC_MAN_SIZE];
}				t_fraction;

void			ft_size_check(const char **format, t_form *form);
void			ft_precision_check(const char **format, t_form *form);
void			ft_width_check(const char **format, t_form *form);
void			ft_flag_check(const char **format, t_form *form);
int				ft_display_37(t_form *form);
int				ft_display_x(t_form *form);
int				ft_display_p(t_form *form);
int				ft_display_o(t_form *form);
int				ft_display_all(t_form *form);
int				ft_display_wc(wint_t wc);
int				ft_display_c(t_form *form);
int				ft_display_d(t_form *form);
int				ft_display_u(t_form *form);
int				ft_put_e(t_form *form, t_fraction *f, int frac_len);
int				ft_display_e(t_form *form, double e);
int				ft_put_f(t_form *form, t_fraction *f, int frac_len);
int				ft_display_f(t_form *form, double f);
void			ft_round_off(t_fraction *f, int exp);
int				ft_put_prepad(t_form *form);
int				ft_check_zero(t_fraction *f, int cal, int result, int ef);
int				ft_put_ge(int fracdig, t_form *form, t_fraction *f);
int				ft_put_gf(int fracdig, int intdig, t_form *form, t_fraction *f);
int				ft_display_g(t_form *form, double g);
int				ft_display_null(t_form *form);
int				ft_wchar_len(wchar_t wc);
int				ft_display_ws(t_form *form, wchar_t *ws);
int				ft_display_s(t_form *form);
void			ft_mul_2(t_fraction *f);
void			ft_mul_5(t_fraction *f);
int				ft_decimal_digits(uint64_t ui);
void			ft_fctoc(t_fraction *f, int len);
void			ft_plus_10pow(t_fraction *f, int exp);
void			ft_cal_exp(t_fraction *f, int exp);
void			ft_cal_man(uint64_t bit, uint64_t len, t_fraction *f);
void			ft_dtof(double d, t_fraction *f);
void			ft_sub_handle_n(t_form *form);
int				ft_handle_n(t_form *form);
int				ft_isnan(double d);
int				ft_display_nan(t_form *form);
int				ft_display_inf(t_form *form);
int				ft_isspecial(double d, t_form *form);
int				ft_printf(const char *format, ...);
void			ft_sub_putnbr_mk2(size_t ui, int base, char *put);
int				ft_uilen(size_t ui, int digit);
int				ft_putnbr_mk2(size_t ui, char *put, int base, t_form *form);
void			ft_initexpput(int exp, char *put);
int				ft_subputfracdig(t_fraction *f, int len);
int				ft_subput_gf(t_fraction *f, int intdig, int fracdig);
long long int	ft_read_ipara(t_form *form);
size_t			ft_read_upara(t_form *form);
int				ft_check_specifier(t_form *form);
int				ft_sub_printf(const char **format, t_form *form);

#endif
