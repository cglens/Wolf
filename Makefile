# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:25:06 by cglens            #+#    #+#              #
#    Updated: 2016/11/15 14:26:00 by cglens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf 

SRC = src/main.c\
	  src/ray.c\
	  src/key_event.c\
	  src/init.c\
	  src/move.c\
	  src/win_2.c\
	  src/map.c\
	  src/color.c

FLAG = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror 

all : $(NAME)

OBJ = $(SRC:.c=.o) 

$(NAME) :
	@make -C libft	
	gcc $(FLAG) -o $(NAME) libft/libft.a $(SRC) -I libft/includes -I includes 
	@echo "enjoy bitch !"
clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "clean \ 0 /"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
