/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:17:39 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/23 16:47:07 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	graphics_mlx(t_all *all)
{
	start_mlx(all);
	return (1);
}

int	start_mlx(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	all->map[all->ye][all->xe] = '0';
	all->mlx = mlx_init();
	if (!all->mlx)
		return (0);
	all->window = mlx_new_window(all->mlx, all->size_x * 64, all->size_y * 64,
			"so_long");
	if (!all->window)
		return (0);
	load_img(all);
	create_map(all, x, y);
	mlx_key_hook(all->window, key_hook, all);
	mlx_hook(all->window, 33, 1L << 17, destroy_all, all);
	mlx_loop(all->mlx);
	return (1);
}

int	load_img(t_all *all)
{
	int			i;
	int			x;
	static char	*pathname[5] = {
		"img/gab.xpm",
		"img/leo.xpm",
		"img/A_black_image.xpm",
		"img/Red_flag.xpm",
		"img/Solid_white.xpm"};

	i = 0;
	while (i < 5)
	{
		all->path_img[i] = mlx_xpm_file_to_image(all->mlx, pathname[i], &x, &x);
		if (!all->path_img[i])
			return (ft_printf("Wrong name for *.xpm \n"), destroy_img(all));
		i++;
	}
	return (1);
}

int	create_map(t_all *all, int x, int y)
{
	while (all->map[++y])
	{
		x = -1;
		while (all->map[y][++x])
		{
			if (all->map[y][x] == '0')
				mlx_put_image_to_window(all->mlx, all->window, all->path_img[2],
					x * 64, y * 64);
			if (all->map[y][x] == '1')
				mlx_put_image_to_window(all->mlx, all->window, all->path_img[3],
					x * 64, y * 64);
			if (all->map[y][x] == 'C')
				mlx_put_image_to_window(all->mlx, all->window, all->path_img[1],
					x * 64, y * 64);
			if (all->map[y][x] == 'P')
				mlx_put_image_to_window(all->mlx, all->window, all->path_img[0],
					x * 64, y * 64);
			if (all->map[y][x] == 'E')
				mlx_put_image_to_window(all->mlx, all->window, all->path_img[4],
					x * 64, y * 64);
		}
	}
	return (1);
}

int	key_hook(int key_code, t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	if (key_code == ESCAPE)
		return (destroy_all(all));
	if (key_code == UP || key_code == ARROWUP)
		postion_p(all, -1, 0);
	if (key_code == DOWN || key_code == ARROWDOWN)
		postion_p(all, 1, 0);
	if (key_code == LEFT || key_code == ARROWLEFT)
		postion_p(all, 0, -1);
	if (key_code == RIGHT || key_code == ARROWRIGHT)
		postion_p(all, 0, 1);
	open_exit(all);
	create_map(all, x, y);
	return (0);
}
