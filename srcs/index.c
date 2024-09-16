/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:59:49 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/30 18:08:21 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av, char **env)
{
	t_all	all;

	if (ac > 2)
		return (ft_printf("Error\nToo much arg\n"), 0);
	if (!env || !*env)
		return (ft_printf("Error\nNo env\n"), 0);
	ft_memset(&all, 0, sizeof(t_all));
	all.filename = av[1];
	if (!all.filename)
		return (ft_printf("Error\nWrong map name\n"), 0);
	if (check_map(&all) == 0)
		return (0);
	if (checkelem(&all) == 0)
		return (ft_printf("Error\nwrong elem\n"), 0);
	check_path(&all);
	graphics_mlx(&all);
	return (0);
}

int	ft_free_struct(t_all *items)
{
	int	i;

	i = 0;
	while (items->maptest[i])
	{
		free(items->maptest[i]);
		i++;
	}
	free(items->maptest);
	i = 0;
	while (items->map[i])
	{
		free(items->map[i]);
		i++;
	}
	free(items->map);
	return (0);
}

int	ft_error(char *str, t_all *items)
{
	if (str[0] == 'E')
	{
		ft_free_struct(items);
		exit(1);
	}
	printf("Error\n-> %s\n", str);
	ft_free_struct(items);
	exit(1);
}

int	exitpath(t_all *items, int x, int y)
{
	if ((items->maptest[y + 1][x] == '0') || (items->maptest[y][x + 1] == '0')
		|| (items->maptest[y - 1][x] == '0') || (items->maptest[y][x
			- 1] == '0') || (items->maptest[y + 1][x] == 'C')
		|| (items->maptest[y][x + 1] == 'C') || (items->maptest[y
			- 1][x] == 'C') || (items->maptest[y][x - 1] == 'C')
		|| (items->maptest[y + 1][x] == 'E') || (items->maptest[y][x
			+ 1] == 'E') || (items->maptest[y - 1][x] == 'E')
		|| (items->maptest[y][x - 1] == 'E'))
		return (1);
	return (0);
}
