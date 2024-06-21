# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:44:09 by moouahab          #+#    #+#              #
#    Updated: 2024/06/19 15:19:04 by moouahab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Cyberpunk Makefile

# Source files
SRCS = main.c m_atol.c init_data.c eating.c cleanup.c security_print.c thraed_func.c time.c
SRCS += died.c eating_utils.c
# Object files
OBJS = ${SRCS:%.c=objs/%.o}

INC_PATH = ./inc/

# Executable name
NAME = philo

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g3 -I$(INC_PATH) #-fsanitize=address 

# Linker flags
LDFLAGS = -lm

# Colors
GREEN   = \033[0;32m
RED     = \033[0;31m
YELLOW  = \033[0;33m
CYAN    = \033[0;36m
RESET   = \033[0m

# Make all rule
all: ${NAME}

# Linking rule
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LDFLAGS}
	
	
	@echo "\e[38;5;207m ██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗ \033[0m"
	@echo "\e[38;5;206m ██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝ \033[0m"
	@echo "\e[38;5;205m ██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗ \033[0m"
	@echo "\e[38;5;204m ██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║ \033[0m"
	@echo "\e[38;5;203m ██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║ \033[0m"
	@echo "\e[38;5;202m ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝ \033[0m"

# Compilation rule for object files
objs/%.o: %.c
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

# Clean rule
clean:
	@rm -rf objs
	@echo "\e[38;5;214m  ██████╗██╗     ███████╗ █████╗ ███╗   ██╗"
	@echo "\e[38;5;215m ██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║"
	@echo "\e[38;5;216m ██║     ██║     █████╗  ███████║██╔██╗ ██║"
	@echo "\e[38;5;217m ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║"
	@echo "\e[38;5;218m ╚██████╗███████╗███████╗██║  ██║██║ ╚████║"
	@echo "\e[38;5;219m  ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝"
# Clean all rule
fclean: clean

	@rm -f ${NAME}
	@echo "\e[38;5;208m ███████╗ ██████╗██╗     ███████╗ █████╗ ███╗   ██╗"
	@echo "\e[38;5;209m ██╔════╝██╔════╝██║     ██╔════╝██╔══██╗████╗  ██║"
	@echo "\e[38;5;210m █████╗  ██║     ██║     █████╗  ███████║██╔██╗ ██║"
	@echo "\e[38;5;211m ██╔══╝  ██║     ██║     ██╔══╝  ██╔══██║██║╚██╗██║"
	@echo "\e[38;5;212m ██║     ╚██████╗███████╗███████╗██║  ██║██║ ╚████║"
	@echo "\e[38;5;213m ╚═╝      ╚═════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝"

# Rebuild rule
re: fclean all

# PHONY targets
.PHONY: all clean fclean re

