# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamil <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 15:49:43 by kamil             #+#    #+#              #
#    Updated: 2024/11/04 14:51:34 by kamil            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g
RM = rm -f

SRCS = utils/ft_atoi.c \
       utils/ft_isdigit.c \
       utils/ft_split.c \
       utils/ft_strdup.c \
       utils/ft_strjoin.c \
       utils/ft_strlcpy.c \
       utils/ft_strlen.c \
       utils/ft_strncmp.c \
       utils/ft_substr.c \
       utils/pw_errors.c \
       utils/pw_utils.c \
       utils/pw_utils2.c \
       movements/sa.c \
       movements/pb.c \
       movements/pa.c \
       movements/rrr.c \
       movements/rrb.c \
       movements/rra.c \
       movements/rr.c \
       movements/rb.c \
       movements/ra.c \
	   sort/sorting.c \
	   sort/sort_utils.c \
	   sort/sort_utils2.c \
	   sort/push_cheapest.c \
	   sort/check_cheapest.c \
	   sort/target.c \
	   sort/big_small.c \
       push_swap.c

OBJS = $(SRCS:.c=.o)

INCLUDES = push_swap.h

all: $(NAME)
	@echo "ok"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "fully cleaned"

re: fclean all

.PHONY: all clean fclean re
