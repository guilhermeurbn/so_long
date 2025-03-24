# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 18:03:16 by guisanto          #+#    #+#              #
#    Updated: 2025/03/24 12:54:01 by guisanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -W -g -Iminilibx-linux

# Detectar sistema operacional (Linux ou macOS)
ifeq ($(shell uname -s),Darwin)
    MLX_FLAGS = -Lmlx -lmlx_Darwin -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
    MLX_LIB = mlx/libmlx_Darwin.a
else
    MLX_FLAGS = -Lmlx -lmlx -lXext -lX11
    MLX_LIB = mlx/libmlx.a
endif

# Diretório do código fonte
SRC = so_long.c utils.c
OBJS = $(SRC:.c=.o)

# Regra principal: compilar o projeto com a biblioteca MLX
all: $(MLX_LIB) $(NAME)

# Compilar arquivos .c para .o
%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

# Como gerar o executável
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Como construir a biblioteca MLX
$(MLX_LIB):
	@echo "...\033[1;33mCompiling mlx...\033[0m"
	@make -C minilibx-linux
	@cp minilibx-linux/libmlx.a mlx/
	@rm -rf minilibx-linux

# Limpar arquivos gerados
clean:
	rm -f $(OBJS)

# Limpar arquivos gerados e o executável
fclean: clean
	rm -f $(NAME)

# Recompilar do zero
re: fclean all

