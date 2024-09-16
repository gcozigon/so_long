/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:26:20 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/23 16:01:44 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_path(t_all *items)
{
	items->maptest[items->yp][items->xp] = 'X';
	while ((items->maptest[items->ye][items->xe] == 'E'
		|| (check_0(items) == 0)) && (change_by_0x(items) == 1))
	{
		check_x(items);
	}
	return (1);
}

int	change_by_x(t_all *items)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (items->maptest[y])
	{
		x = -1;
		while (items->maptest[y][++x])
		{
			if (items->maptest[y][x] == 'X')
			{
				if (items->maptest[y + 1][x] != '1')
					items->maptest[y + 1][x] = 'X';
				if (items->maptest[y][x + 1] != '1')
					items->maptest[y][x + 1] = 'X';
				if (items->maptest[y - 1][x] != '1')
					items->maptest[y - 1][x] = 'X';
				if (items->maptest[y][x - 1] != '1')
					items->maptest[y][x - 1] = 'X';
			}
		}
		y++;
	}
	return (1);
}

int	change_by_0x(t_all *items)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (items->maptest[y])
	{
		x = 0;
		while (items->maptest[y][x])
		{
			if (items->maptest[y][x] == 'X')
				if (exitpath(items, x, y))
					return (1);
			x++;
		}
		y++;
	}
	return (ft_error("path invalid", items));
}

int	check_x(t_all *items)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (items->maptest[y])
	{
		x = 0;
		while (items->maptest[y][x])
		{
			if (items->maptest[y][x] == 'X')
			{
				change_by_x(items);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_0(t_all *items)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (items->maptest[y])
	{
		x = 0;
		while (items->maptest[y][x])
		{
			if (items->maptest[y][x] == 'C')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
