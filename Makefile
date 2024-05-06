# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 16:09:26 by cshingai          #+#    #+#              #
#    Updated: 2024/04/24 17:12:02 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =
FLAGS = -Wall -Werror -Wextra
LIBFT = lib/libft
FT_PRINTF = lib/ft_printf
CLIENT = client
SERVER = server
HEADER = -I $(LIBFT)
LIB = $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a

# Source files
SRCS_CLIENT = src/client.c
SRCS_SERVER = src/server.c

# Object files derived from source files
OBJ_SERVER = $(SRCS_SERVER:src/%.c=obj/%.o)

all: libft ft_printf $(SERVER)

# Building the main executable
$(SERVER): libft ft_printf $(OBJ_SERVER)
	@echo "Entrou NAME"
	@echo $(OBJ_SERVER)
	cc $(FLAGS) $(OBJ_SERVER) $(LIB) $(HEADER) -o $(SERVER)


# Building libraries
libft:
	@make -C $(LIBFT) all

ft_printf:
	@make -C $(FT_PRINTF) all

# Compilation rule for object files
obj/%.o: %.c
	@cc $(FLAGS) -c $(HEADER) $< -o $@
	@printf "Everything have been build.⭐😁"

obj:
	@mkdir -p obj

# Clean up object files
clean:
	@echo "Removing objects..."
	@rm -rf $(OBJ_SERVER)
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)
	@printf "All objects were removed.🧹💨💨"

# Remove object files and executables
fclean: clean
	@echo "Removing executables..."
	@rm -rf $(SERVER)
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@echo "Executables removed.🤖🧹💨💨"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
