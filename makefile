# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 18:03:16 by guisanto          #+#    #+#              #
#    Updated: 2025/03/31 14:04:03 by guisanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

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
	@echo "$(GREEN)✓ Compilação concluída com sucesso!$(RESET)"

# Compilar arquivos .c para .o
%.o: %.c
	@echo "$(BLUE)Compilando: $<$(RESET)"
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

# Como gerar o executável
$(NAME): $(OBJS)
	@echo "$(YELLOW)🔧 Ligando os arquivos...$(RESET)"
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)🚀 Executável pronto: $(NAME)$(RESET)"

# Como construir a biblioteca MLX
$(MLX_LIB):
	@echo "$(YELLOW)🔨 Compilando a minilibx...$(RESET)"
	@make -C minilibx-linux
	@cp minilibx-linux/libmlx.a mlx/
	@rm -rf minilibx-linux

# Limpar arquivos gerados
clean:
	@echo "$(RED)🗑  Removendo arquivos objeto...$(RESET)"
	rm -f $(OBJS)

# Limpar arquivos gerados e o executável
fclean: clean
	@echo "$(RED)🔥 Removendo executável...$(RESET)"
	rm -f $(NAME)

# Recompilar do zero
re: fclean all
	@echo "$(GREEN)🔄 Recompilação completa!$(RESET)"
