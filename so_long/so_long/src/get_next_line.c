/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:03 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:20:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/get_next_line.h"

char	*trim_linebreak(char *str)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	line = ft_strdup(str);
	if (line == 0)
		return (NULL);
	while (str[i] != '\n')
		i++;
	line[i] = '\0';
	j = 0;
	i++;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
	return (line);
}

int	check_reading(int *read_sym, char *buff)
{
	if (*read_sym < 0)
	{
		if (buff)
			free(buff);
		return (0);
	}
	return (1);
}

char	*read_cycle(char *ost, int fd, int read_sym)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!is_has_linebreak(ost))
	{
		read_sym = read(fd, buff, BUFFER_SIZE);
		if (!check_reading(&read_sym, buff))
			return (NULL);
		buff[read_sym] = '\0';
		if (read_sym == 0)
			break ;
		ost = ft_strjoin_gnl(ost, buff);
		if (ost == 0)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (ost);
}

void	free_ost(char **ost)
{
	free(*ost);
	*ost = 0;
}

char	*get_next_line(int fd)
{
	static char	*ost = 0;
	char		*line;

	if (fd < 0 || fd > 1024)
		return (NULL);
	ost = read_cycle(ost, fd, 0);
	if (!ost)
		return (NULL);
	if (is_has_linebreak(ost))
	{
		line = trim_linebreak(ost);
		if (line == 0)
		{
			free(ost);
			return (NULL);
		}
		if (*ost == '\0')
			free_ost(&ost);
	}
	else
	{
		line = ost;
		ost = 0;
	}
	return (line);
}
