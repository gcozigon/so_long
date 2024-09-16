/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:43:16 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/23 16:39:11 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_p(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'P')
				return (1);
			x++;
		}
		y++;
	}
	return (destroy_all(all));
}

int	postion_p(t_all *all, int ymoove, int xmoove)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (x < all->size_x)
		{
			if (all->map[y][x] == 'P')
			{
				if (all->map[y + ymoove][x + xmoove] != '1')
				{
					all->map[y][x] = '0';
					all->map[y + ymoove][x + xmoove] = 'P';
					return (ft_printf("Moove : %d \n", ++all->count), 1);
				}
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	destroy_img(t_all *all)
{
	int	i;

	i = 0;
	while (all->path_img[i])
	{
		mlx_destroy_image(all->mlx, all->path_img[i]);
		i++;
	}
	mlx_clear_window(all->mlx, all->window);
	mlx_destroy_window(all->mlx, all->window);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	ft_error("End Game !", all);
	return (1);
}

int	destroy_all(t_all *all)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(all->mlx, all->path_img[i]);
		i++;
	}
	mlx_clear_window(all->mlx, all->window);
	mlx_destroy_window(all->mlx, all->window);
	mlx_destroy_display(all->mlx);
	free(all->mlx);
	ft_error("End Game !", all);
	return (1);
}

int	open_exit(t_all *all)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	x = 0;
	y = 0;
	while (all->map[y])
	{
		x = 0;
		while (all->map[y][x])
		{
			if (all->map[y][x] == 'C')
				c = c + 1;
			x++;
		}
		y++;
	}
	if (c <= 0)
		return (all->map[all->ye][all->xe] = 'E', check_p(all), 1);
	return (0);
}
