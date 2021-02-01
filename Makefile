# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/06 12:58:52 by hrizkiou          #+#    #+#              #
#    Updated: 2020/02/16 19:14:36 by hrizkiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = main.c checkmap.c storemap.c draw.c keyhook.c bonus.c more_bonus.c
NAME = fdf

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME):$(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(MFLAGS) -o $(NAME)
#all: $(NAME)
clean:
	@make clean -C libft
	@rm -rf $(OBJS)

fclean:
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
