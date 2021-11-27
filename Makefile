# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/25 13:19:25 by rmatsuka          #+#    #+#              #
#    Updated: 2021/05/08 17:28:52 by rmatsuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_put_d.c \
			ft_put_s.c \
			ft_put_u.c \
			ft_put_p.c \
			ft_put_hex.c

OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
LIBC	=	ar rcs
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean	all

.PHONY:		all clean fclean re
