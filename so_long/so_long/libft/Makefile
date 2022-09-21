CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
LIB		= ar -rcs

NAME	= libft.a

INCLUDE	= libft.h
SRC		= 	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_tolower.c ft_toupper.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strdup.c \
			ft_atoi.c ft_calloc.c ft_bzero.c ft_substr.c ft_strjoin.c\
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_S	=   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ		= $(SRC:.c=.o)
BONUS_O	= $(BONUS_S:.c=.o)

.PHONY: 	all clean fclean re bonus rebonus

all: 		$(NAME)

$(NAME):	$(OBJ) $(INCLUDE)
			$(LIB) $(NAME) $(OBJ)

bonus:		$(BONUS_O) $(INCLUDE)
			$(LIB) $(NAME) $(BONUS_O)

.c.o:		$(INCLUDE)
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJ) $(BONUS_O)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

rebonus:	fclean bonus

run:		$(NAME)
			$(RM) a.out
			$(CC) $(CFLAGS)	main.c libft.a && ./a.out