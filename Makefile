# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 16:09:26 by cshingai          #+#    #+#              #
#    Updated: 2024/05/17 18:52:34 by cshingai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
LIBFT = lib/libft
FT_PRINTF = lib/ft_printf
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
HEADER = -I $(LIBFT)
LIB = $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a

# Source files
SRCS_CLIENT = src/client.c
SRCS_SERVER = src/server.c

# Bonus
SRCS_CLIENT_BONUS = src/client_bonus.c
SRCS_SERVER_BONUS = src/server_bonus.c

# Object files derived from source files
OBJ_SERVER = $(SRCS_SERVER:src/%.c=obj/%.o)
OBJ_CLIENT = $(SRCS_CLIENT:src/%.c=obj/%.o)

OBJ_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:src/%.c=obj/%.o)
OBJ_SERVER_BONUS = $(SRCS_SERVER_BONUS:src/%.c=obj/%.o)

all: libft ft_printf $(SERVER) $(CLIENT)
bonus: libft ft_printf $(SERVER_BONUS) $(CLIENT_BONUS)

# Building the main executable
$(SERVER): libft ft_printf $(OBJ_SERVER)
	@echo "Entrou NAME"
	@echo $(OBJ_SERVER)
	@cc $(FLAGS) $(OBJ_SERVER) $(LIB) $(HEADER) -g3 -o $(SERVER)

$(CLIENT): libft ft_printf $(OBJ_CLIENT)
	@echo "Entrou NAME"
	@echo $(OBJ_CLIENT)
	@cc $(FLAGS) $(OBJ_CLIENT) $(LIB) $(HEADER) -g3 -o $(CLIENT)

# Building bonus executables
$(SERVER_BONUS): libft ft_printf $(OBJ_SERVER_BONUS)
	@echo "Entrou NAME"
	@echo $(OBJ_SERVER_BONUS)
	@cc $(FLAGS) $(OBJ_SERVER_BONUS) $(LIB) $(HEADER) -g3 -o $(SERVER_BONUS)

$(CLIENT_BONUS): libft ft_printf $(OBJ_CLIENT_BONUS)
	@echo "Entrou CLIENT"
	@echo $(OBJ_CLIENT_BONUS)
	@cc $(FLAGS) $(OBJ_CLIENT_BONUS) $(LIB) $(HEADER) -g3 -o $(CLIENT_BONUS)

# Building libraries
libft:
	@make -C $(LIBFT) all

ft_printf:
	@make -C $(FT_PRINTF) all

# Compilation rule for object files
obj/%.o: src/%.c
	@mkdir -p obj
	@cc $(FLAGS) -c $(HEADER) $< -o $@
	@printf "Everything have been build.⭐😁"

# Clean up object files
clean:
	@echo "Removing objects..."
	@rm -rf $(OBJ_SERVER)
	@rm -rf $(OBJ_CLIENT)
	@rm -rf $(OBJ_SERVER_BONUS)
	@rm -rf $(OBJ_CLIENT_BONUS)
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)
	@printf "All objects were removed.🧹💨💨\n"

# Remove object files and executables
fclean: clean
	@echo "Removing executables..."
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)
	@rm -rf $(SERVER_BONUS)
	@rm -rf $(CLIENT_BONUS)
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@echo "Executables removed.🤖🧹💨💨"

# Rebuild everything
re: fclean all

.PHONY: all bonus clean fclean re test
