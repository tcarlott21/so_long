/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:18 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:20:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

void	is_rectangular(t_slg *slg)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (slg->heigth == 0)
		ft_error("Empty map");
	slg->width = ft_strlen(slg->map[0]);
	while (i < slg->heigth)
	{
		j = 0;
		while (j < slg->width)
		{
			if (ft_strlen(slg->map[i]) != slg->width)
				ft_error("Invalid map");
			j++;
		}
		i++;
	}
}

void	is_has_border(t_slg *slg)
{
	size_t	i;
	size_t	j;
	size_t	lastletter;
	size_t	lowestletter;

	i = 0;
	lastletter = slg->width - 1;
	lowestletter = slg->heigth - 1;
	while (i < slg->heigth)
	{
		j = 0;
		while (j < slg->width)
		{
			if ((slg->map[0][j] != '1') || (slg->map[lowestletter][j] != '1') \
			|| (slg->map[i][0] != '1') || (slg->map[i][lastletter] != '1'))
				ft_error("Wrong border");
			j++;
		}
		i++;
	}
	slg->p = 0;
	slg->c = 0;
	slg->e = 0;
}

void	cndtls_for_pce(t_slg *slg, size_t i, size_t j)
{
	if (slg->map[i][j] == 'P')
	{
		slg->p++;
		slg->p_i = i;
		slg->p_j = j;
	}
	else if (slg->map[i][j] == 'E')
			slg->e++;
	else if (slg->map[i][j] == 'C')
			slg->c++;
}

void	is_has_pce(t_slg *slg)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < slg->heigth)
	{
		j = -1;
		while (++j < slg->width)
		{
			if (slg->map[i][j] == 'P' || slg->map[i][j] == 'E'
			|| slg->map[i][j] == 'C'
			|| slg->map[i][j] == '0' || slg->map[i][j] == '1')
				cndtls_for_pce(slg, i, j);
			else
				ft_error("Invalid map");
		}
	}
}

void	ft_map_errors(t_slg *slg)
{
	if (slg->p != 1 || slg->e < 1)
		ft_error("Wrong number of players or exits");
	if (slg->c < 1)
		ft_error("Wrong number of collectibles");
}
