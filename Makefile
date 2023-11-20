# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricont <maricont@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 17:52:08 by maricont          #+#    #+#              #
#    Updated: 2023/05/12 17:26:53 by maricont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_ptr_hexa.c ft_hexa.c ft_decimal.c ft_decimal_uns.c

#SRCSBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

#OBJSBONUS = $(SRCSBONUS:.c=.o)

INCLUDE = -I ./
RM = rm -f
DEPS = $(SRCS:.c=.d)

#DEPS_BONUS = $(SRCSBONUS:.c=.d)

%.o: %.c
	${CC} ${CFLAGS} -MMD $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

-include $(DEPS)

#bonus: $(OBJSBONUS)
#	ar -rcs $(NAME) $(OBJSBONUS)

#-include $(DEPS_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
#	$(RM) $(OBJSBONUS)
#	$(RM) $(DEPS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
