/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:14:33 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/23 16:07:06 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(t_all *newadd)
{
	char	*str;
	char	**map;
	char	**mapfinal;
	int		i;

	i = 0;
	str = readfile(newadd);
	if (!str || !*str)
		return (free(str), 0);
	if (str[i] == '\n')
		return (ft_printf("Error\n(delete first line)\n"), free(str), 0);
	if (str[ft_strlen(str) - 1] == '\n')
		return (ft_printf("Error\n(delete last line)\n"), free(str), 0);
	if (!another_ascii(str))
		return (ft_printf("Error\n(wrong ascii)\n"), free(str), 0);
	map = ft_split(str, '\n');
	mapfinal = ft_split(str, '\n');
	if (!map || !mapfinal)
		return (free(str), 0);
	newadd->maptest = map;
	newadd->map = mapfinal;
	if (check_length(map) == 0 || check_bordure(map) == 0)
		return (free(str), ft_error("length or border\n", newadd));
	return (free(str), 1);
}

char	*readfile(t_all *items)
{
	int		i;
	char	*buff;
	char	*temp;
	int		fd;

	i = 1;
	buff = ft_calloc(2, 1);
	temp = ft_calloc(2, 1);
	if (!buff || !temp)
		return (NULL);
	fd = open(items->filename, O_RDONLY);
	if (fd < 0)
		return (free(buff), free(temp), NULL);
	while (i)
	{
		i = read(fd, temp, 1);
		if (i == -1)
			return (close(fd), free(buff), free(temp), NULL);
		if (i == 0)
			break ;
		buff = ft_strjoin000(buff, temp);
	}
	return (free(temp), close(fd), buff);
}

int	another_ascii(char *str)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	j = 0;
	x = ft_strlen(str);
	while ((str[i] == 'C' || str[i] == '1' || str[i] == '0' || str[i] == '\n'
			|| str[i] == 'E' || str[i] == 'P'))
		i++;
	if (i != x)
		return (0);
	while (str[j])
	{
		if ((str[j] == '\n') && (str[j + 1] == '\n'))
			return (0);
		j++;
	}
	return (1);
}

int	check_length(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((ft_strlen(map[i]) != ft_strlen(map[0])))
			return (ft_printf("MAP INVALIDE (length)"), 0);
		i++;
	}
	return (1);
}

int	check_bordure(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while ((map[0][j]))
	{
		if ((map[0][j] != '1') || (map[i - 1][j] != '1'))
			return (0);
		j++;
	}
	j = 0;
	i = ft_strlen(map[0]);
	while ((map[j]))
	{
		if ((map[j][0] != '1') || (map[j][i - 1] != '1'))
			return (0);
		j++;
	}
	return (1);
}
