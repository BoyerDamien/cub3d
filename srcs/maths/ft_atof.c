#include "cub3d.h"

double ft_atof(char *str)
{
	double result;
	int i;

	i = 0;
	if (str)
	{
		while (*str && ft_isspace(*str))
			str++;
		result = ft_atoi(str);
		while (*str && !ft_cinset(*str, " .,"))
			str++;
		if (*str && *str == '.')
			str++;
		if (*str && ft_isdigit(*str))
		{
			while (str[i] && ft_isdigit(str[i]))
				i++;
			if (result < 0)
				result = result - ft_atoi(str) / pow(10, i);
			else
				result = result + ft_atoi(str) / pow(10, i);
		}
		return (result);
	}
	return (0);
}

