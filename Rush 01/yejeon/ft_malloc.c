#include "ft_malloc.h"

void	ft_malloc_init(void *arr, unsigned int size)	// 동적할당 범위의 내용 0으로 초기화
{
	char	*p;

	p = (char*)arr;
	while (size)
	{
		p[size - 1] = 0;
		size--;
	}
}

void	ft_malloc_free(void **buf)
{
	unsigned int	i;

	i = 0;
	while (i < MAX_MALLOC_BUF_SIZE)
	{
		if (buf[i])
			free(buf[i]);
		buf[i++] = 0;
	}
}

void	*ft_malloc(unsigned int type_size, unsigned int len)	// 동적할당 관리 함수		type_size : 자료형 크기		len : 배열길이
{
	static void		*buf[MAX_MALLOC_BUF_SIZE] = {0};		// 동적할당 주소들 관리
	unsigned int	i;
	void			*p;

	if (type_size * len)
	{
		p = malloc(type_size * len);
		if (p)
		{
			ft_malloc_init(p, type_size * len);
			i = 0;
			while (i < MAX_MALLOC_BUF_SIZE)
			{
				if(buf[i] == 0)		// 저장공간이 있으면 저장
				{
					buf[i] = p;
					return (p);		// 성공적으로 작업완료시 동적할당된 주소 반환
				}
			i++;
			}
			if (p)	// 저장공간을 찾지못했을 경우
				free(p);
			return (0);
		}
	}
	else
		ft_malloc_free(buf);
	return (0);
}

// type_size 와 len 이 둘다 0, 0이면 buf에 있는 동적할당 모두 free
void	ft_free(void)	// 외부에서 free() 먼저 지워버리면 터진다
{
	ft_malloc(0, 0);
}
