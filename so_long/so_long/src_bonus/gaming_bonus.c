/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:37 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:20:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long_bonus.h"

void	move_w(t_slg *slg)
{
	size_t	i;
	size_t	j;

	i = slg->p_i;
	j = slg->p_j;
	if (slg->map [i - 1][j] == '0' || slg->map [i - 1][j] == 'C')
	{
		if (slg->map [i - 1][j] == 'C')
			slg->c--;
		slg->map [i - 1][j] = 'P';
		slg->map [i][j] = '0';
		slg->p_i--;
		printf("%d moves\n", ++slg->moves);
	}
	else if ((slg->map [i - 1][j] == 'E') && (!slg->c))
	{
		ft_putendl_fd("Game Over!", 1);
		exit (0);
	}
	else if (slg->map [i - 1][j] == 'K')
	{
		gameover(slg, i, j);
	}
}

void	move_s(t_slg *slg)
{
	size_t	i;
	size_t	j;

	i = slg->p_i;
	j = slg->p_j;
	if (slg->map [i + 1][j] == '0' || slg->map [i + 1][j] == 'C')
	{
		if (slg->map [i + 1][j] == 'C')
			slg->c--;
		slg->map [i + 1][j] = 'P';
		slg->map [i][j] = '0';
		slg->p_i++;
		printf("%d moves\n", ++slg->moves);
	}
	else if ((slg->map [i + 1][j] == 'E') && (!slg->c))
	{
		ft_putendl_fd("Game Over!", 1);
		exit (0);
	}
	else if (slg->map [i + 1][j] == 'K')
	{
		gameover(slg, i, j);
	}
}

void	move_a(t_slg *slg)
{
	size_t	i;
	size_t	j;

	i = slg->p_i;
	j = slg->p_j;
	if (slg->map [i][j - 1] == '0' || slg->map [i][j - 1] == 'C')
	{
		if (slg->map [i][j - 1] == 'C')
			slg->c--;
		slg->map [i][j - 1] = 'P';
		slg->map [i][j] = '0';
		slg->p_j--;
		printf("%d moves\n", ++slg->moves);
	}
	else if ((slg->map [i][j - 1] == 'E') && (!slg->c))
	{
		ft_putendl_fd("Game Over!", 1);
		exit (0);
	}
	else if (slg->map [i][j - 1] == 'K')
	{
		gameover(slg, i, j);
	}
}

void	move_d(t_slg *slg)
{
	size_t	i;
	size_t	j;

	i = slg->p_i;
	j = slg->p_j;
	if (slg->map [i][j + 1] == '0' || slg->map [i][j + 1] == 'C')
	{
		if (slg->map [i][j + 1] == 'C')
			slg->c--;
		slg->map [i][j + 1] = 'P';
		slg->map [i][j] = '0';
		slg->p_j++;
		printf("%d moves\n", ++slg->moves);
	}
	else if ((slg->map [i][j + 1] == 'E') && (!slg->c))
	{
		ft_putendl_fd("Game Over!", 1);
		exit (0);
	}
	else if (slg->map [i][j + 1] == 'K')
	{
		gameover(slg, i, j);
	}
}

void	gaming(t_slg *slg, int keycode)
{
	if (keycode == W)
		move_w(slg);
	if (keycode == S)
		move_s(slg);
	if (keycode == A)
		move_a(slg);
	if (keycode == D)
		move_d(slg);
	map_render_init(slg);
}
