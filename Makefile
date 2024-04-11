# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 17:44:09 by moouahab          #+#    #+#              #
#    Updated: 2024/04/08 23:54:29 by moouahab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Cyberpunk Makefile

# Source files
SRCS = srcs/main.c function/error/msg_error.c function/parse/parsing.c function/parse/utils_parse.c
SRCS += function/parse/get_time.c function/parse/birth_of_philosopher.c function/error/msg_thread.c
SRCS += function/config/threads.c function/config/routing.c function/config/simulation.c 


# Object files
OBJS = ${SRCS:%.c=objs/%.o}

INC_PATH = ./include/

# Executable name
NAME = philosophers

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra  -g3 -MMD -I$(INC_PATH) -O2

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
	@echo "${CYAN}Linking cybermodules into cyberprogram...${RESET}"
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LDFLAGS}
	@echo "${GREEN}Cyberprogram successfully compiled!${RESET}"

# Compilation rule for object files
objs/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "${YELLOW}Compiling $< into $@...${RESET}"
	@${CC} ${CFLAGS} -c $< -o $@

# Clean rule
clean:
	@rm -rf objs

# Clean all rule
fclean: clean
	@echo "${RED}Removing cyberprogram...${RESET}"
	rm -f ${NAME}
	@echo "${GREEN}Cyberprogram removed.${RESET}"

# Rebuild rule
re: fclean all

# PHONY targets
.PHONY: all clean fclean re

