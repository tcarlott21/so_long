/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:21:05 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:21:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long_bonus.h"

void	draw_map_else_else(t_slg *slg, size_t	x, size_t	y)
{
	if (slg->map[y][x] == 'K')
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->enemy, x * 64, y * 64);
	}
	else if (slg->map[y][x] == 'D')
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->death, x * 64, y * 64);
	}
	else if (slg->map[y][x] == 'P')
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->field, x * 64, y * 64);
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, \
		slg->player, x * 64, y * 64);
	}
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
	draw_map_else_else(slg, x, y);
}

void	draw_map(t_slg *slg)
{
	size_t	x;
	size_t	y;

	mlx_clear_window(slg->mlx, slg->mlx_win);
	y = 0;
	while (y < slg->heigth)
	{
		x = 0;
		while (x < slg->width)
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
			draw_map_else(slg, x, y);
			x++;
		}
		y++;
	}
}

void	map_render_init(t_slg *slg)
{
	draw_map(slg);
	my_mlx_str_put_moves(slg);
}
