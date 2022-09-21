/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:13 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:20:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	if (str)
		ft_putendl_fd(str, 2);
	else
		perror(0);
	exit (-1);
}

int	count_strings(int fd)
{
	int		amount;
	char	*s;

	amount = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		free(s);
		amount++;
	}
	return (amount);
}

void	making_map(char *map_name, t_slg *slg, int fd)
{
	size_t	i;

	i = 0;
	slg->heigth = count_strings(fd);
	close(fd);
	slg->map = malloc(sizeof(char *) * (slg->heigth + 1));
	if (!slg->map)
		ft_error(NULL);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	while (i < slg->heigth)
	{
		slg->map[i] = get_next_line(fd);
		if (slg->map[i] == NULL)
			ft_error("Invalid map");
		i++;
	}
	slg->map[i] = NULL;
}

int	check_map_file(char *map_name)
{
	int	fd;

	if (ft_strncmp(map_name + (ft_strlen(map_name) - 4), ".ber", 4))
		ft_error("Invalid map file");
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	if (read(fd, NULL, 0) < 0)
		ft_error(NULL);
	return (fd);
}

void	parsing(char *map_name, t_slg *slg)
{
	int	fd;

	fd = check_map_file(map_name);
	making_map(map_name, slg, fd);
	is_rectangular(slg);
	is_has_border(slg);
	is_has_pce(slg);
	ft_map_errors(slg);
}
