/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:21:00 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:21:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long_bonus.h"

int	key_hook(int keycode, t_slg *slg)
{
	if (keycode == 53)
		exit (0);
	gaming(slg, keycode);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_slg	slg;

	if (argc != 2)
		return (ft_error("Number of argument must be 2"));
	init_struct(&slg);
	parsing(argv[1], &slg);
	slg.mlx = mlx_init();
	slg.mlx_win = mlx_new_window(slg.mlx, slg.width * 64, \
							slg.heigth * 64, "./so_long");
	init_textures(&slg);
	map_render_init(&slg);
	mlx_loop_hook(slg.mlx, animation_player, &slg);
	mlx_hook(slg.mlx_win, 17, 0, ft_exit, 0);
	mlx_hook(slg.mlx_win, 2, 0, key_hook, &slg);
	mlx_loop(slg.mlx);
	return (0);
}
