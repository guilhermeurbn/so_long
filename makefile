# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 18:03:16 by guisanto          #+#    #+#              #
#    Updated: 2025/03/23 12:37:30 by guisanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Detectar sistema operacional (Linux ou macOS)
UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
    INCLUDES = -I/opt/X11/include -Imlx
    MLX_FLAGS = -Lmlx -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
    MLX_LIB = mlx/libmlx_Darwin.a
    MLX_DIR = ./mlx
else
    INCLUDES = -I/usr/include -Imlx_linux
    MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
    MLX_LIB = mlx/libmlx.a
    MLX_DIR = ./minilibx-linux
endif

# Arquivos fontes
SRC = so_long.c utils.c
OBJS = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@echo "\033[1;33mCompiling MLX...\033[0m"
	@make -C $(MLX_DIR)
	@if [ "$(UNAME)" = "Linux" ]; then cp minilibx-linux/libmlx.a mlx/; fi

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

