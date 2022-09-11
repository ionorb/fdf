NAME		= 	fdf.a

SRCS		= 	ft_atoi.c ft_split.c main.c read_file.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				minilibx/libmlx.a

OBJS		= 	$(SRCS:.c=.o)

CC			= 	gcc

CCFLAGS 	= 	-Wall -Wextra -Werror -D BUFFER_SIZE=100 
.c.o:
			$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

compile:	$(NAME)
			gcc $(NAME) -o fdf

clean:
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
			rm -f $(NAME)

cclean:		compile fclean

re:			fclean all

.PHONY:		all clean fclean re cclean compile
