# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleger <fleger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 23:44:48 by fleger            #+#    #+#              #
#    Updated: 2019/12/20 08:08:12 by fleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

all: ${NAME}

CFLAGS		= -Wall -Wextra -Werror

GCC 		= gcc

RM 			= rm -f

HEAD 		= ft_printf.h
 
SRCS =  ft_perp.c ft_perx.c ft_printf.c ft_printf_utils.c ft_struct.c ft_addchar.c ft_printf_utils2.c ft_nbr.c ft_display.c ft_parsing.c

OBJS =	ft_perp.o ft_perx.o ft_printf.o ft_printf_utils.o ft_struct.o ft_addchar.o ft_printf_utils2.o ft_nbr.o ft_display.o ft_parsing.o

$(NAME):	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}
.c.o:
		${GCC} ${CFLAGS} -c $< -I ${HEAD} -o ${<:.c=.o}
clean:
		${RM} ${OBJS}

re:			fclean all

fclean:			clean
		${RM} ${NAME}

.PHONY: re clean fclean all bonus 