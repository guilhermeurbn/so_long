LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./libraries/mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a

SOURCES_FILES	=	so_long.c \
					draw.c \
					exit_games.c \
					gameplay.c \
					init.c \
					map_checker.c \
					player_update.c \
					read_map.c

SOURCES_DIR		=	sources

HEADER			=	$(SOURCES_DIR)/so_long.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx-linux

# Detectar sistema operacional (Linux ou macOS)
ifeq ($(shell uname -s),Darwin)
    MLX_FLAGS = -L$(MINILIBX_PATH) -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
    MLX_LIB = $(MINILIBX_PATH)/libmlx_Darwin.a
else
    MLX_FLAGS = -L$(MINILIBX_PATH) -lmlx -lXext -lX11
    MLX_LIB = $(MINILIBX_PATH)/libmlx.a
endif

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MINILIBX_PATH) clean
	@$(RM) $(OBJECTS)

fclean:			clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft minilibx
