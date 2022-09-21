/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:23 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:20:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void	get_textures(t_slg *slg)
{
	slg->field = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/field.xpm", &slg->img_width, &slg->img_height);
	slg->wall = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/wall.xpm", &slg->img_width, &slg->img_height);
	slg->player = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/player.xpm", &slg->img_width, &slg->img_height);
	slg->ex = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/ex.xpm", &slg->img_width, &slg->img_height);
	slg->coll = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/coll.xpm", &slg->img_width, &slg->img_height);
	slg->closed_ex = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/closed_ex.xpm", &slg->img_width, &slg->img_height);
	slg->gameover = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/game_over.xpm", &slg->img_width, &slg->img_height);
}

void	draw_map_else(t_slg *slg, size_t	x, size_t	y)
{
	if (slg->map[y][x] == 'C')
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->coll, x * 64, y * 64);
	}
	else if (slg->map[y][x] == 'E' && slg->c)
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
				slg->closed_ex, x * 64, y * 64);
	}
	else if (slg->map[y][x] == 'E' && !slg->c)
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
				slg->ex, x * 64, y * 64);
	}
}

void	draw_map(t_slg *slg, size_t	x, size_t	y)
{
	if (slg->map[y][x] == '1')
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->wall, x * 64, y * 64);
	}
	else if (slg->map[y][x] == '0')
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
	else if (slg->map[y][x] == 'P')
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->player, x * 64, y * 64);
	}
	draw_map_else(slg, x, y);
}

void	map_render_init(t_slg *slg)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < slg->heigth)
	{
		x = 0;
		while (x < slg->width)
		{
			draw_map(slg, x, y);
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_slg *slg)
{
	if (keycode == 53)
		exit (0);
	gaming(slg, keycode);
	return (0);
}
