/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:52 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:20:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_struct(t_slg *slg)
{
	slg->p = 0;
	slg->c = 0;
	slg->e = 0;
	slg->width = 0;
	slg->heigth = 0;
	slg->count_img = 0;
	slg->ani = 0;
	slg->flag = 0;
	slg->moves = 0;
}

void	init_textures(t_slg *slg)
{
	slg->field = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/field.xpm", &slg->img_width, &slg->img_height);
	slg->wall = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/wall.xpm", &slg->img_width, &slg->img_height);
	slg->player1 = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/player1.xpm", &slg->img_width, &slg->img_height);
	slg->player2 = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/player2.xpm", &slg->img_width, &slg->img_height);
	slg->player = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/player1.xpm", &slg->img_width, &slg->img_height);
	slg->ex = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/ex.xpm", &slg->img_width, &slg->img_height);
	slg->coll = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/coll.xpm", &slg->img_width, &slg->img_height);
	slg->closed_ex = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/closed_ex.xpm", &slg->img_width, &slg->img_height);
	slg->enemy = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/enemy1.xpm", &slg->img_width, &slg->img_height);
	slg->enemy1 = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/enemy1.xpm", &slg->img_width, &slg->img_height);
	slg->enemy2 = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/enemy2.xpm", &slg->img_width, &slg->img_height);
	slg->death = mlx_xpm_file_to_image(slg->mlx, \
	"./textures/death.xpm", &slg->img_width, &slg->img_height);
}
