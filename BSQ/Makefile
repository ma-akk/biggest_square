# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtresa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/06 22:08:20 by gtresa            #+#    #+#              #
#    Updated: 2020/11/04 17:11:30 by gtresa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c check_map.c check_ftline.c fill_map.c ft_create_elem.c ft_malloc.c ft_putchar.c ft_putstr.c result.c output.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

FLAGS	= -Wall -Wextra -Werror

HEADERS	= ft_bsq.h

TESTFILE = tmp.txt

.c.o:
		gcc ${FLAGS} -c $< -o ${<:.c=.o}

all:	${OBJS}	
		gcc ${FLAGS} ${OBJS} -I ${HEADERS} -o ${NAME}

NAME:	all

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME} ${TESTFILE}
		
.PHONY:	all clean fclean
