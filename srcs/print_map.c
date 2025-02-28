#include "so_long.h"

void	print_map(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		printf("%s", tab[i]);
}