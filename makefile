# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 14:55:57 by guisanto          #+#    #+#              #
#    Updated: 2025/03/12 16:02:23 by guisanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a
# O diretório de cabeçalhos da MiniLibX
MLX_LIB = minilibx_macos/libmlx.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(OBJ) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	
$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(MLX_LIB):
	make -C minilibx_macos

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all