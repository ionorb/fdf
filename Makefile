LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MLX_LINUX_PATH	=	./libs/mlx-linux
MLX_LINUX		=	$(MLX_LINUX_PATH)/libmlx.a

SOURCES_FILES	=	draw.c main.c read_file.c get_next_line.c key_press.c \
					project.c init.c utils.c color.c grid.c

SOURCES_DIR		=	sources

HEADER			=	$(SOURCES_DIR)/fdf.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

MAKE			=	make

NAME			=	fdf

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-g3 -Wall -Wextra -Werror -D BUFFER_SIZE=100
MLX_LINUX_FLAGS	=	-L. -lXext -L. -lX11 -lm -lbsd

.c.o:		
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX_LINUX) $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(HEADER) $(MLX_LINUX) $(MLX_LINUX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_LINUX):
	$(MAKE) -C $(MLX_LINUX_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_LINUX_PATH) clean
	$(RM) $(OBJECTS)

fclean:		clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft minilibx
