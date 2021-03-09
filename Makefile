# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 19:40:16 by mslyther          #+#    #+#              #
#    Updated: 2021/03/09 21:51:17 by tjamis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
SRCS_LIST = *.c
SRCS_PATH = ./sources/
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_LIST))
GCC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM = rm -rf

.PHONY: all clean fclean re

all:	${SRCS} 
		${GCC} ${FLAGS} ${SRCS} main.c -o ${NAME}

clean:	fclean

fclean:
		${RM} ${NAME}

re:		fclean all
		