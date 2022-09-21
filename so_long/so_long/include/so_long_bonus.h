/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:14:37 by user              #+#    #+#             */
/*   Updated: 2022/05/06 18:14:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_slg {
	char		**map;
	size_t		heigth;
	size_t		width;
	size_t		p;
	size_t		e;
	size_t		c;
	size_t		k;
	size_t		p_i;
	size_t		p_j;
	void		*mlx;
	void		*mlx_win;
	void		*field;
	void		*player;
	void		*player1;
	void		*player2;
	void		*ex;
	void		*coll;
	void		*wall;
	void		*enemy;
	void		*enemy1;
	void		*enemy2;
	void		*closed_ex;
	void		*death;
	void		*gameover;
	int			img_width;
	int			img_height;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			moves;
	int			sprite;
	int			count_img;
	int			ani;
	int			x_gameover;
	int			y_gameover;
	int			flag;
}				t_slg;

int		ft_error(char *str);
void	is_rectangular(t_slg *slg);
void	is_has_border(t_slg *slg);
void	is_has_pce(t_slg *slg);
void	ft_map_errors(t_slg *slg);
void	parsing(char *map_name, t_slg *slg);
void	map_render_init(t_slg *slg);
void	gaming(t_slg *slg, int keycode);
int		ft_exit(void);
int		key_hook(int keycode, t_slg *slg);
void	init_textures(t_slg *slg);
int		animation_player(t_slg *slg);
int		animation_enemy(t_slg *slg);
int		color(int t, int r, int g, int b);
void	my_mlx_str_put_moves(t_slg *slg);
void	init_struct(t_slg *slg);
void	gameover(t_slg *slg, int i, int j);

#endif
