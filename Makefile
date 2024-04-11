# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 16:09:26 by cshingai          #+#    #+#              #
#    Updated: 2024/04/11 16:30:43 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
FLAGS = -Wall -Werror -Wextra
LIBFT = lib/libft
FT_PRINTF = lib/ft_printf
CLIENT = client
SERVER = server
HEADER = -I $(LIBFT)

LIB = $(LIBFT)/libft.a $(FT_PRINTF)/ft_printf.a

SRCS = client.c

OBJ = &(SRCS: %c:%o)

all: $(NAME)

$(NAME): libft ft_printf $(OBJ)
			@cc $(FLAGS) $(OBJ) $(lib) $(HEADER) -o $(NAME)

libft:
		@make -C $(LIBFT) all

ft_printf:
		@make -C $(FT_PRINTF) all

obj/%.o: %.c
		@cc $(FLAGS) -c $(HEADER) $< -o $@
		@printf "Compiling..."

clean:
		@printf "Removing objects...🧹💨💨"
		@rm -rf $(OBJ)
		@make clean -C $(LIBFT)
		@make clean -C $(FT_PRINTF)
		@printf "Everthing was removed.🤘"

fclean:
		@printf "Removing executables...🤖🧹💨💨"
		@rm -rf $(NAME)
		@make fclean -C $(LIBFT)
		@make fclean -C $(FT_PRINTF)
		@printf "Everthing was removed.💪"

re: fclean all

.PHONY: all, clean, fclean, re
