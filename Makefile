# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 14:48:13 by stda-sil          #+#    #+#              #
#    Updated: 2025/03/11 17:46:45 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = Libft
RM = rm -rf
BONUS = checker
SRCS = ft_checks.c \
ft_push.c \
ft_reverse_rotate.c \
ft_rotate.c \
ft_stacks.c \
ft_swap.c \
ft_utils.c \
ft_algorit_shorts.c \
ft_utils_alg.c \
ft_algorit_long.c \
ft_calc_rot.c \
ft_comb_rot.c \
ft_type_rot.c \

SRCS_MAIN = mainpush.c \

SRCS_BONUS = ft_checker_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS_MAIN:.c=.o)

BONUS_OBJ =$(SRCS_BONUS:.c=.o)

INCLUDE = -L ./Libft -lft

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(OBJS2)
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS2) -o $(NAME) ${INCLUDE}

$(BONUS): $(OBJS) $(BONUS_OBJ)
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJ) -o $(BONUS) ${INCLUDE}

all: $(NAME)

bonus: $(BONUS)

clean:
	$(RM) $(OBJS) $(OBJS2) $(BONUS_OBJ)
	@make -s -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@make -s -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
