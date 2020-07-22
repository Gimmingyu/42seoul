#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_noti(const char *msg)	// 메시지 바로 출력
{
	const char	*p;

	p = msg;
	while (*p)
		p++;
	write(1, msg, p - msg);
}

int		ft_atoi(char *data)		// 나중에 2자리 이상의 수를 받을때 사용
{
	int		i;

	i = 0;
	while (*data)
	{
		if (*data == ' ')
			break ;
		i *= 10;
		i += (int)(*data - '0');
		data++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	static char	buf[11];	// 10번째는 항상 0 값
	int			i;

	i = 0;
	while (i < 11)
		buf[i++] = 0;
	i = 9;
	while (i)
	{
		buf[i] = (n % 10) + '0';
		if (n / 10)
			n = n / 10;
		else
			break ;
		i--;
	}
	return &buf[i];
}

int		ft_check_input_cnt(int *data)		// 정사각형을 만들수있는 충분한 수인지 검사
{
	int		n;
	int 	x;

	n = data[0];	// 0번 인수에 배열의 길이가 저장
	x = 1;
	while (x * x <= n)
	{
		if (x * x == n)
			return (1);
		x++;
	}
	return (0);
}

int		ft_check_input_format(char *data)	// 숫자 + 공백만 있는지 검사
{
	while (*data)
	{
		if (!(('0' <= *data && *data <= '9') || (' ' == *data)))
			return (0);
		data++;
	}
	return (1);
}

int		*ft_check_input_set_num(int n, char **input)
{
	int		num_buf[1024];
	int		num_cnt;
	int		i;
	int		flag;
	char	*p;
	int		*p_result;

	num_cnt = 0;
	i = 1;	// 0 : 실행파일명 (항상 주의)
	while (i < n)
	{
		flag = 1;	// 공백 다음 숫자일때 1
		p = input[i];
		while(*p)
		{
			if (*p != ' ' && flag)
			{
				num_buf[num_cnt++] = ft_atoi(p);
				flag = 0;
			}
			else if (*p == ' ')
				flag = 1;
			p++;
		}
		i++;
	}
	p_result = 0;
	p_result = (int*)ft_malloc(sizeof(int), num_cnt + 1);	// 동적할당한 배열의 크기를 저장할 공간 +1
	if (p_result)	// 동적할당 성공하면 값 대입 시작
	{
		i = 0;
		while (i <= num_cnt)
		{
			p_result[i + 1] = num_buf[i];
			i++;
		}
		p_result[0] = num_cnt;
	}
	return (p_result);
}

int		*ft_check_input(int n, char **input)		// 입력값 검증 함수
{
	int		*p_result_input;	// 숫자값을 저장한 동적할당 배열 포인터
	int		i;

	i = 1;	// 0 : 실행파일명 (항상 주의)
	while (i < n)
	{
		if (!ft_check_input_format(input[i]))
		{
			ft_noti("ERROR\n");
			return (0);
		}
		i++;
	}
	p_result_input = ft_check_input_set_num(n, input);
	if (p_result_input)
	{
		if (!ft_check_input_cnt(p_result_input))
			ft_noti("ERROR\n");
		else
			return (p_result_input);
	}
	return (0);
}

void	ft_write_buffer(const char *str, unsigned int len)	// 한번에 wirte로 출력 하기위한 임시버퍼 함수 ft_print()에서만 사용
{
	static unsigned char	buf[1024];
	static unsigned int		i = 0;

	if (str && len)
	{
		while (len)
		{
			buf[i++] = *(str++);
			if (i == 1024)	// 버퍼가득차면 출력
			{
				write(1, buf, i);
				i = 0;
			}
			len--;
		}
	}
	else	// 0 으로 신호를 주면 출력
	{
		write(1, buf, i);
		i = 0;
	}
}

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*(str + n++))
	{
	}
	return (n-1);
}

void	ft_print(int **map, int n)
{
	int		row;
	int		col;
	int		len;
	char 	*p;

	row = 1;
	while (row <= n)
	{
		col = 1;
		while (col <= n)
		{
			p = ft_itoa(map[row][col]);
			len = ft_strlen(p);
			ft_write_buffer(p, len);
			if (col != n)	// 마지막 열이 아니면 ' ' 추가
				ft_write_buffer(" ", 1);
			col++;
		}
		ft_write_buffer("\n", 1);
		row++;
	}
	ft_write_buffer(0, 0);	// 출력!
}

int	main(int argc, char *argv[])
{
	int		*p_result_input;

	if (argc < 2)
	{
		ft_noti("need to number\n");
		return (0);
	}
	p_result_input = ft_check_input(argc, argv);
	if (p_result_input)
	{
		//ft_init();
		//ft_run();
		//ft_print();
		ft_free();
	}
	return (0);
}
