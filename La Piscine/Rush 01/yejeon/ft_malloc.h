#ifndef FT_MALLOC_H
#define FT_MALLOC_H

#include <stdlib.h>
#define	MAX_MALLOC_BUF_SIZE 1024

void	ft_malloc_init(void *arr, unsigned int size);
void	ft_malloc_free(void **buf);
void	*ft_malloc(unsigned int type_size, unsigned int len);
void	ft_free(void);
#endif
