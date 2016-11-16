# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:25:06 by cglens            #+#    #+#              #
#    Updated: 2016/11/16 14:37:50 by cglens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf 

SRC = src/main.c\
	  src/ray.c\
	  src/key_event.c\
	  src/init.c\
	  src/move.c\
	  src/map.c\
	  src/color.c

FLAG = -lmlx -framework OpenGL -framework AppKit -Wall -Wextra -Werror 

OBJ = $(SRC:.c=.o)

EXEC = wolf

$(NAME) :
	@make -C libft	
	@gcc $(FLAG) -o $(EXEC) libft/libft.a $(SRC) -I libft/includes -I includes 
	@echo "enjoy bitch !"
clean:
	@rm -f $(OBJ)
	@make clean -C libft
	@echo "clean \ 0 /"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
