#include <stdio.h>

void	print_cmd_v(char **cmd_v)
{
	int	i;

	i = 0;
	while (cmd_v[i])
	{
		printf("cmd_v[%d]: %s\n", i, cmd_v[i]);
		i++;
	}
}

void	ft_puts(char *s)
{
	printf("%s\n", s);
}