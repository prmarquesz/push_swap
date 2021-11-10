/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:52:38 by proberto          #+#    #+#             */
/*   Updated: 2021/11/10 12:26:10 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

# define TRUE 1
# define FALSE 0
# define SWAP 5
# define PUSH 6
# define ROTATE 7
# define REVERSE 8
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef enum e_swap {
	SA,
	SB,
	SS
}			t_swap;

typedef enum e_rotate {
	RA,
	RB,
	RR
}			t_rotate;

typedef enum e_reverse_rotate {
	RRA,
	RRB,
	RRR
}			t_reverse_rotate;

typedef struct s_stack {
	int	*array;
	int	size;
	int	len;
	int	top;
	int	smaller;
	int	larger;
	int	sorted;
}		t_stack;

void	ft_swap(t_stack *stack_a, t_stack *stack_b, t_swap op);
void	ft_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_push_b(t_stack *stack_b, t_stack *stack_a);
void	ft_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate op);
void	ft_reverse_rotate(t_stack *stack_a, t_stack *stack_b,
			t_reverse_rotate op);
int		ft_is_sorted(int *array, int i, int len);
int		ft_get_smallest(int *array, int len, int i, int ref);
int		ft_get_smallest_index(int *array, int i, int len);
int		ft_get_biggest(int *array, int len, int i, int ref);
int		ft_get_biggest_index(int *array, int i, int len);
void	ft_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_soft_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_medium_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_hard_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_extremely_hard_sorting(t_stack *stack_a, t_stack *stack_b);

#endif
