/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:14:42 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/23 16:01:44 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	checkelem(t_all *items)
{
	if (two_e_p(items) == 0)
		return (ft_error("MAP INVALIDE", items));
	if (keep_p(items) == 0)
		return (ft_error("MAP INVALIDE", items));
	if (keep_e(items) == 0)
		return (ft_error("MAP INVALIDE", items));
	if (keep_c(items) == 0)
		return (ft_error("MAP INVALIDE", items));
	return (1);
}

int	keep_p(t_all *items)
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
			if (items->maptest[y][x] == 'P')
			{
				items->yp = y;
				items->xp = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (ft_error("No Player", items));
}

int	keep_e(t_all *items)
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
			if (items->maptest[y][x] == 'E')
			{
				items->ye = y;
				items->xe = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (ft_error("No Player", items));
}

int	keep_c(t_all *items)
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
				items->nbcollect = items->nbcollect + 1;
			x++;
		}
		y++;
	}
	if (items->nbcollect > 0)
		return (1);
	return (ft_error("No Collect", items));
}

int	two_e_p(t_all *items)
{
	int	x;
	int	y;
	int	ep;

	ep = 0;
	x = 0;
	y = 0;
	while (items->maptest[y])
	{
		x = 0;
		while (items->maptest[y][x])
		{
			if (items->maptest[y][x] == 'E' || items->maptest[y][x] == 'P')
				ep = ep + 1;
			x++;
		}
		y++;
	}
	items->size_x = x;
	items->size_y = y;
	if (ep > 2)
		return (ft_error("They are too many E or P\n", items));
	return (1);
}
