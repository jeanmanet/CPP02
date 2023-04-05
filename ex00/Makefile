# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmanet <jmanet@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 08:34:06 by jmanet            #+#    #+#              #
#    Updated: 2023/04/05 11:25:35 by jmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

FLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = ${wildcard *.cpp}

OBJS = ${SRCS:.cpp=.o}

HEADERS = ${wildcard *.hpp}

CC = g++

all : ${NAME}

${NAME} : ${OBJS} ${HEADERS}
	${CC} ${FLAGS} ${SRCS} -o ${NAME}


clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
