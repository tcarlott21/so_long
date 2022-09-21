/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:08 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:20:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	ft_exit(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_slg	slg;

	if (argc != 2)
		return (ft_error("Number of argument must be 2"));
	parsing(argv[1], &slg);
	slg.mlx = mlx_init();
	slg.mlx_win = mlx_new_window(slg.mlx, slg.width * 64, \
							slg.heigth * 64, "./so_long");
	get_textures(&slg);
	map_render_init(&slg);
	mlx_hook(slg.mlx_win, 17, 0, ft_exit, 0);
	mlx_hook(slg.mlx_win, 2, 0, key_hook, &slg);
	mlx_loop(slg.mlx);
	return (0);
}
