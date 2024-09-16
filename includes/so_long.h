/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcozigon <gcozigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:43:16 by gcozigon          #+#    #+#             */
/*   Updated: 2023/05/23 16:02:12 by gcozigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define ARROWUP 65362
# define ARROWDOWN 65364
# define ARROWLEFT 65361
# define ARROWRIGHT 65363
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESCAPE 65307

typedef struct s_all
{
	char	**map;
	char	**maptest;
	int		yp;
	int		xp;
	int		ye;
	int		xe;
	int		size_x;
	int		size_y;
	char	*filename;
	void	*path_img[5];
	void	*mlx;
	void	*window;
	int		count;
	int		nbcollect;
}			t_all;

int			check_map(t_all *items);
char		*readfile(t_all *items);
int			another_ascii(char *str);
int			check_length(char **map);
int			check_bordure(char **map);
int			checkelem(t_all *items);
int			two_e_p(t_all *items);
int			keep_p(t_all *items);
int			keep_e(t_all *items);
int			keep_c(t_all *items);
void		ft_freestruct(void);
int			check_path(t_all *items);
int			exitpath(t_all *items, int x, int y);
int			change_by_x(t_all *items);
int			check_x(t_all *items);
int			check_0(t_all *items);
int			change_by_0x(t_all *items);
int			ft_free_struct(t_all *items);
int			ft_error(char *str, t_all *items);
int			graphics_mlx(t_all *all);
int			start_mlx(t_all *all);
int			key_hook(int key_code, t_all *all);
int			load_img(t_all *all);
int			create_map(t_all *all, int x, int y);
int			key_hook(int key_code, t_all *all);
int			check_p(t_all *all);
int			postion_p(t_all *all, int ymoove, int xmoove);
int			open_exit(t_all *all);
int			destroy_img(t_all *all);
int			destroy_all(t_all *all);

#endif
