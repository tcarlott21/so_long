NAME	=	so_long
NAME_B	=	so_long_bonus

SRCS_F	=	parsing.c\
			solong.c \
			get_next_line.c \
			get_next_line_utils.c\
			reading_map.c\
			gaming.c\
			main.c
SRCS_D	=	src/

SRCS_F_B	=	parsing_bonus.c\
			map_render_bonus.c\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			reading_map_bonus.c\
			gaming_bonus.c\
			animation.c\
			mlx_writes.c\
			init_struct.c\
			main_bonus.c
SRCS_D_B	=	src_bonus/

INCLUDE = include/get_next_line.h include/so_long_bonus.h include/so_long.h


OBJS	=	$(SRCS:.c=.o)

OBJS_B	=	$(SRCS_B:.c=.o)

CC  	=	gcc

CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	$(addprefix $(SRCS_D),$(SRCS_F))
SRCS_B	=	$(addprefix $(SRCS_D_B),$(SRCS_F_B))

MLX		=	-L . -lmlx -framework OpenGL -framework AppKit
LIBFT	=	./libft/libft.a

$(NAME)	:	$(OBJS)  $(INCLUDE)
			$(MAKE) -C $(dir $(LIBFT))
			$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) -o $(NAME)

all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean	:	
			$(MAKE) clean -C $(dir $(LIBFT))
			rm -rf $(OBJS) $(OBJS:.o=.d) $(OBJS_B)

fclean	:	clean
			rm -rf $(NAME) $(NAME_B)

bonus	:	$(OBJS_B) $(INCLUDE)
			$(MAKE) -C $(dir $(LIBFT))
			$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS_B) -o $(NAME_B)
			

re		:	fclean all

.PHONY	:	all clean fclean re bonus
