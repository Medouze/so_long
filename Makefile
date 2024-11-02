# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlavergn <mlavergn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 11:31:10 by mlavergn          #+#    #+#              #
#    Updated: 2024/11/02 19:22:01 by mlavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long
DIR         = srcs/
GNL         = gnl/
PRINTF_DIR  = ft_printf/
PRINTF_LIB  = $(PRINTF_DIR)libftprintf.a
CC          = gcc
FLAGS       = -Wall -Werror -Wextra
MFLAGS      = -L/usr/local/lib -lmlx -L$(PRINTF_DIR) -lftprintf -framework OpenGL -framework AppKit

SRCS =      $(GNL)get_next_line.c $(GNL)get_next_line_utils.c $(DIR)parsing.c $(DIR)main.c \
            $(DIR)utils.c  $(DIR)check_map.c $(DIR)mlx_utils.c $(DIR)image.c \
            $(DIR)directions.c $(DIR)find_path.c $(DIR)utils2.c

OBJS =      $(SRCS:.c=.o)

all: $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c | $(PRINTF_LIB)
	$(CC) $(FLAGS) -I/usr/local/include -I$(PRINTF_DIR) -I$(DIR) -I$(GNL) -c $< -o $@

$(NAME): $(OBJS) $(PRINTF_LIB)
	$(CC) $(FLAGS) $(OBJS) $(MFLAGS) -o $(NAME)
	
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re


