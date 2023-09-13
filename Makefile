# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npaolett <npaolett@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 17:44:12 by npaolett          #+#    #+#              #
#    Updated: 2023/06/22 14:30:43 by npaolett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g -s
RM 		= rm -f

SRC = 	get_node.c  \
		main_utils.c \
		stack_init.c  \
		swap_et_push.c \
		rotate.c        \
		rotate_rev.c     \
		ft_atoi2.c        \
		count_rrr.c        \
		found_maxmin.c      \
		log.c                \
		logic_a.c             \
		pivot.c	               \
		push_swap.c             \
		division.c               \
		

OBJ	= 	${SRC:.c=.o}


%.o%.c: ${SRC} 
		$(CC) ${CFLAGS} -c -o $@ $< 

${NAME}:	${OBJ}
			${CC} ${CFLAGS} $^ -o $@
		
all: 	${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean  all  

.PHONY: bonus all clean fclean re
