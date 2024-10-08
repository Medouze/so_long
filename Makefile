# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlavergn <mlavergn@s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 11:31:10 by mlavergn          #+#    #+#              #
#    Updated: 2024/08/25 02:37:03 by mlavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
DIR		= srcs/
GNL		= gnl/
PRINTF_DIR = ft_printf/
MLX_DIR = mlx/
MLX		= $(MLX_DIR)libmlx.a
PRINTF	= $(PRINTF_DIR)libftprintf.a
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g -fsanitize=address
MFLAGS	= -L$(MLX_DIR) -lmlx -L$(PRINTF_DIR) -lftprintf -L/usr/lib -lXext -lX11 -lm -lz

SRCS =	$(GNL)get_next_line.c $(GNL)get_next_line_utils.c $(DIR)parsing.c $(DIR)main.c \
		$(DIR)utils.c  $(DIR)check_map.c $(DIR)mlx_utils.c $(DIR)image.c \
		$(DIR)directions.c $(DIR)find_path.c $(DIR)utils2.c

OBJS = $(SRCS:.c=.o)

all: $(MLX) $(PRINTF) $(NAME)

$(MLX):
	make -sC $(MLX_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I$(MLX_DIR) -I$(PRINTF_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MFLAGS) -o $(NAME)

norm:
	norminette -R CheckDefine

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re norm