/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:21:32 by proberto          #+#    #+#             */
/*   Updated: 2021/10/28 22:38:01 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Shift down all elements of stack a by 1. The last element becomes 
 * the first one.
 * @param stack The stack to be rotated.
 * @return TRUE if the rotation was successful, FALSE otherwise.
*/
static int	ft_reverse_rotate_a(t_stack *stack)
{
	int	tmp;
	int	i;
	int	count;

	count = 0;
	if (stack->size > 1)
	{
		tmp = stack->stack[stack->len - 1];
		i = stack->len - 1;
		while (count++ < stack->size - 1)
		{
			stack->stack[i] = stack->stack[i - 1];
			i--;
		}
		stack->stack[i] = tmp;
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Shift down all elements of stack b by 1. The last element becomes 
 * the first one.
 * @param stack The stack to be rotated.
 * @return TRUE if the rotation was successful, FALSE otherwise.
*/
static int	ft_reverse_rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;
	int	count;

	count = 0;
	if (stack->size > 1)
	{
		tmp = stack->stack[stack->top];
		i = stack->top;
		while (count++ < stack->size - 1)
		{
			stack->stack[i] = stack->stack[i + 1];
			i++;
		}
		stack->stack[i] = tmp;
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Triggers down shift rotation functions.
 * @param stack The stack to be rotated.
 * @param op The operation to be performed (rra, rrb, rrr).
 * @return Void.
*/
void	ft_reverse_rotate(t_stack *stack_a, t_stack *stack_b,
		t_reverse_rotate op)
{
	int	response_a;
	int	response_b;

	if (op == RRA)
	{
		if (ft_reverse_rotate_a(stack_a))
			write(1, "rra\n", 4);
	}
	else if (op == RRB)
	{
		if (ft_reverse_rotate_b(stack_b))
			write(1, "rrb\n", 4);
	}
	else
	{
		response_a = ft_reverse_rotate_a(stack_a);
		response_b = ft_reverse_rotate_b(stack_b);
		if (response_a && response_b)
			write(1, "rrr\n", 4);
		else if (response_a)
			write(1, "rra\n", 4);
		else if (response_b)
			write(1, "rrb\n", 4);
	}
}
