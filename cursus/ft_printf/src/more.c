#include "../ft_printf.h"

int	ft_strlen(const char *s)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	char_in_chaset(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (c);
		set++;
	}
	return (0);
}
int	ft_atoi_s(const char *str, int *i)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + str[*i] - '0';
		(*i)++;
	}
	(*i)--;
	return (result);
}
