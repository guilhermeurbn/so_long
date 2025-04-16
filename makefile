# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 18:03:16 by guisanto          #+#    #+#              #
#    Updated: 2025/04/16 01:37:06 by guisanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)

# Diretórios
SRC_DIR = sources
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = mlx

# Detectar sistema operacional (Linux ou macOS)
ifeq ($(shell uname -s),Darwin)
    MLX_FLAGS = -L$(MLX_DIR) -lmlx_Darwin -framework OpenGL -framework AppKit
    MLX_LIB = $(MLX_DIR)/libmlx_Darwin.a
else
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11
    MLX_LIB = $(MLX_DIR)/libmlx.a
endif

# Arquivos fonte
SRC = $(SRC_DIR)/so_long.c \
      $(SRC_DIR)/draw.c \
      $(SRC_DIR)/init.c \
      $(SRC_DIR)/read_map.c \
      $(SRC_DIR)/map_validate.c \
      $(SRC_DIR)/player_update.c \
      $(SRC_DIR)/gameplay.c \
      $(SRC_DIR)/exit_game.c
	  
OBJECTS = $(SOURCES:.c=.o)

# Regra principal: compilar o projeto
all: $(MLX_LIB) $(NAME)
	@echo "$(GREEN)✓ Compilação concluída com sucesso!$(RESET)"

# Criar diretório obj se não existir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilar arquivos .c para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(BLUE)Compilando: $<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

# Como gerar o executável
$(NAME): $(OBJECTS)
	@echo "$(YELLOW)🔧 Ligando os arquivos...$(RESET)"
	$(CC) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)🚀 Executável pronto: $(NAME)$(RESET)"

# Como construir a biblioteca MLX
$(MLX_LIB):
	@echo "$(YELLOW)🔨 Compilando a minilibx...$(RESET)"
	@make -C $(MLX_DIR) all

# Limpar arquivos gerados
clean:
	@echo "$(RED)🗑  Removendo arquivos objeto...$(RESET)"
	rm -rf $(OBJ_DIR)

# Limpar arquivos gerados e o executável
fclean: clean
	@echo "$(RED)🔥 Removendo executável...$(RESET)"
	rm -f $(NAME)

# Recompilar do zero
re: fclean all
	@echo "$(GREEN)🔄 Recompilação completa!$(RESET)"
