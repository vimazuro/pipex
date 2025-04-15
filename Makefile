# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 11:26:33 by vimazuro          #+#    #+#              #
#    Updated: 2025/03/04 15:21:53 by vimazuro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
SRC_DIR = .
LIBFT_INC_DIR = libft/include 
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
HEADER = pipex.h
LIBFT_HEADERS = libft/include/libft.h libft/include/ft_printf.h \
		libft/include/get_next_line.h

SRC_FILES = src/main.c src/check_argv.c src/print_error.c \
			src/open_files.c src/free_array.c \
			src/execute_command.c src/child_process.c \
			src/find_full_path.c src/process_commands.c \
			src/create_pipes.c src/create_process.c \
			src/write_tmp_file.c 

OBJS = $(LIBFT_LIB) $(SRC_FILES:.c=.o)

all: makelibft $(NAME)

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(LIBFT_INC_DIR) -o $(NAME) $(OBJS) $(LIBFT_LIB)

%.o: %.c $(HEADER) $(LIBFT_HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(LIBFT_INC_DIR) -c $< -o $@

clean:
	rm -f $(SRC_FILES:.c=.o)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re makelibft
