/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:57:03 by dboyer            #+#    #+#             */
/*   Updated: 2020/04/21 18:16:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dst != NULL && src != NULL)
	{
		i = 0;
		if (dstsize == 0)
			return (ft_strlen(src));
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(src));
	}
	return (0);
}

char		*ft_strdup(const char *s1)
{
	char *copy;

	if (s1 != NULL)
	{
		if (!(copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
			return (NULL);
		ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
		return (copy);
	}
	return (NULL);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (dst != NULL && src != NULL)
	{
		i = 0;
		src_len = ft_strlen(src);
		dst_len = ft_strlen(dst);
		if (dstsize < dst_len)
			return (dstsize + src_len);
		while (src[i] && dst_len + i < dstsize - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (dst_len + src_len);
	}
	return (0);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*concat;

	if (s1 != NULL && s2 != NULL)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		if (!(concat = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
			return (NULL);
		ft_strlcpy(concat, s1, s1_len + 1);
		ft_strlcat(concat, s2, s2_len + s1_len + 1);
		return (concat);
	}
	return (ft_strdup("\0"));
}

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		if (start >= ft_strlen(s) || !(*s) || len == 0)
			return (ft_strdup("\0"));
		if (!(str = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (ft_strdup("\0"));
}
