#include "ft_h.h"

void	ft_read_txt(char *dict_name)
{
	FILE *file;
	char line[255];

	file = fopen(dict_name, "r");
	while (fgets(line, sizeof(line), file) != NULL)
		printf("%s", line);
	fclose(file);
}