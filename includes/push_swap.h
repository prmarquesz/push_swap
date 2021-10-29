/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:52:38 by proberto          #+#    #+#             */
/*   Updated: 2021/10/28 21:35:42 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

# define TRUE 1
# define FALSE 1

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
	int	*stack;
	int	size;
	int	len;
	int	top;
}		t_stack;

void	ft_swap(t_stack *stack_a, t_stack *stack_b, t_swap op);
void	ft_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_push_b(t_stack *stack_b, t_stack *stack_a);
void	ft_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate op);
void	ft_reverse_rotate(t_stack *stack_a, t_stack *stack_b,
			t_reverse_rotate op);

#endif
