# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:25:06 by cglens            #+#    #+#              #
#    Updated: 2016/11/04 15:49:14 by cglens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf 

SRC = src/asdf.c\
	  src/key_event.c

FLAG = -lmlx -framework OpenGL -framework AppKit 

OBJ = $(SRC:.c=.o) 

$(NAME) :
	@make -C libft	
	@gcc $(FLAG) -o $(NAME) libft/libft.a $(SRC) -I libft/includes
	@echo "enjoy bitch !"
clean:
	@make clean -C libft
	@rm -f $(OBJ) $(NAME)
	@echo "clean \ 0 /"

fclean: clean
	@make fclean -C libft

re: fclean $(NAME)

.PHONY: clean fclean re
