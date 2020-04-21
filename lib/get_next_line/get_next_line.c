/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:35:32 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 18:15:44 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

int		append_stock(char **stock, char *buffer)
{
	char	*new;

	if (*stock == NULL && buffer != NULL)
	{
		*stock = ft_strdup(buffer);
		return (1);
	}
	else if (*stock != NULL)
	{
		new = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = new;
		return (1);
	}
	return (0);
}

void	update_stock(char **stock, int i)
{
	char *temp;

	if ((*stock)[i + 1])
	{
		temp = ft_strdup(&((*stock)[i + 1]));
		free(*stock);
		*stock = temp;
	}
	else
	{
		free(*stock);
		*stock = NULL;
	}
}

int		append_line(char **line, char **stock)
{
	int		i;

	if (*stock != NULL)
	{
		i = 0;
		while ((*stock)[i])
		{
			if ((*stock)[i] == '\n')
			{
				*line = ft_substr(*stock, 0, i);
				update_stock(stock, i);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buffer[ BUFFER_SIZE ];
	static char *stock = NULL;

	if (fd >= 0 && BUFFER_SIZE > 0 && line != NULL && !read(fd, buffer, 0))
	{
		while ((ret = read(fd, buffer, BUFFER_SIZE)))
		{
			buffer[ret] = '\0';
			append_stock(&stock, buffer);
			if (append_line(line, &stock))
				return (1);
		}
		if (append_line(line, &stock))
			return (1);
		*line = stock != NULL ? ft_strdup(stock) : ft_strdup("\0");
		if (stock != NULL)
		{
			free(stock);
			stock = NULL;
		}
		return (0);
	}
	return (-1);
}
