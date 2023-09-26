# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 15:43:26 by vipalaci          #+#    #+#              #
#    Updated: 2023/09/26 15:43:29 by vipalaci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	gcc
CFLAGS	=	-g -pthread -fsanitize=thread
#CFLAGS	=	-Wall -Wextra -Werror -g -pthread
RM		=	rm -rf

SRC		=	$(addprefix src/, init.c main.c philoacts.c philocontrol.c timeutils.c utils.c)
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all



.PHONY: all clean fclean re