# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-oiri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 13:24:21 by cel-oiri          #+#    #+#              #
#    Updated: 2019/11/23 06:34:26 by cel-oiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC =	main.c \
		affichlist.c \
		freels.c \
		lstinsr.c \
		flags.c \
		error.c \
		parsing.c \
		init_stuff.c \
		pars_directory.c \
		fill_ltav.c \
		fill_ltav_tf.c \
		create_lt.c \
		fill_ltav_r.c \
		fill_ltav_rft.c \
		read_dir_br.c \
		read_dir.c \
		file_helper1.c \
		show_file_lf.c \
		fill_stuff.c \
		ltinsr_tflag.c \
		insert_fct.c \
		show_time.c \
		show_size.c \
		show_pw_grname.c
OBJ = $(SRC:.c=.o)
C = gcc
FLAGS = -Wall -Werror -Wextra
LIB = -L./libft -lft
LIBFT = libft
LFT = lft
HEADER = ls.h

all: $(LFT) $(NAME)

$(LFT):
	make -C $(LIBFT)

$(NAME): $(OBJ)
	$(C) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c $(HEADER)
	$(C) $(FLAGS) -o $@ -c $<

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
