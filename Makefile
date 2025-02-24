# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camerico <camerico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:15:24 by camerico          #+#    #+#              #
#    Updated: 2025/02/24 17:28:39 by camerico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

# dossiers
LIBFT_DIR 	=	libft/
MLX_DIR		=	minilibx-linux/
SRCS_DIR	=	srcs/
OBJ_DIR		=	obj/

SRCS = main.c \
	create_map.c \
	mouvement.c \
	parsing.c \

HEADER = so_long.h

SRCS_SOLONG 	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS_SOLONG 	= 	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

# ajout de MLX
MLX 	= 	$(MLX_DIR)/libmlx.a
MLXFLAGS = 	-L$(MLX_DIR) -lmlx -lXext -lX11

# ajout de la libft
LIBFT = $(LIBFT_DIR)/libft.a

# compilation
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS_SOLONG)
	$(CC) $(CFLAGS) $(OBJS_SOLONG) $(MLXFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
