/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:05:09 by gcozigon          #+#    #+#             */
/*   Updated: 2023/01/13 21:56:52 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen000(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_read_line(int fd, char *buffer)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (i > 0 && !ft_strchr000(buffer, '\n'))
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
			return (free(tmp), NULL);
		tmp[i] = '\0';
		buffer = ft_strjoin000(buffer, tmp);
		if (!buffer || !*buffer)
			return (free(buffer), free(tmp), NULL);
	}
	return (free(tmp), buffer);
}

char	*keep_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	line = ft_strcpy(line, buffer);
	return (line);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	i++;
	str = ft_calloc((ft_strlen000(buffer) - i) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (buffer[i])
	{
		str[j] = buffer[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buff = ft_read_line(fd, buff);
	if (!buff)
		return (NULL);
	line = keep_line(buff);
	if (!line)
		return (NULL);
	buff = next_line(buff);
	return (line);
}
