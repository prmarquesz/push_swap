# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 23:47:42 by proberto          #+#    #+#              #
#    Updated: 2021/11/13 02:21:32 by proberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_PUSH_SWAP_H = includes/
PATH_LIBFT = src/libft/
PATH_VALIDATION = src/main/validation
PATH_OPERATIONS = src/main/operations
PATH_SORTING = src/main/sorting

NAME = push_swap
LIBFT = src/libft/libft.a
MAIN = src/main/push_swap.c
SRC = $(addprefix $(PATH_VALIDATION)/, stack_validation.c utils.c) \
$(addprefix  $(PATH_OPERATIONS)/, push.c swap.c rotate.c reverse_rotate.c) \
$(addprefix $(PATH_SORTING)/, soft_sorting.c medium_sorting.c hard_sorting.c \
extremely_hard_sorting.c sorting.c utils.c)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(LIBFT)
	$(CC) $(CFLAGS) $(MAIN) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):	
	@$(MAKE) -C $(PATH_LIBFT)

clean:
	@$(RM) $(NAME)
	@$(MAKE) clean -C $(PATH_LIBFT)

fclean:	clean
	@$(MAKE) fclean -C $(PATH_LIBFT)

re:	fclean all

norminette:
	norminette $(PATH_PUSH_SWAP_H) $(PATH_LIBFT) $(MAIN) $(SRC)

.PHONY: all clean fclean re run exe
