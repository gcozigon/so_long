/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:40:14 by gcozigon          #+#    #+#             */
/*   Updated: 2023/02/10 19:56:47 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin000(char *s1, char *s2)
{
	int		i;
	char	*str;
	int		len;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
		return (free(s1), ft_strdup000(s2));
	len = ft_strlen000((char *)s1) + ft_strlen000((char *)s2);
	str = (char *)malloc(sizeof(char) * ((len) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}

char	*ft_strchr000(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	dest[++i] = '\0';
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(nmemb * size);
	if (mem == 0)
		return (NULL);
	while (i < nmemb * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strdup000(char *x)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen000(x);
	dest = malloc(sizeof(char) * len + 1);
	if (dest == 0)
		return (NULL);
	while (x[i])
	{
		dest[i] = x[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
