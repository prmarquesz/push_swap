/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:11:37 by proberto          #+#    #+#             */
/*   Updated: 2021/10/28 22:34:35 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Shift up all elements of stack a by 1. The first element becomes 
 * the last one.
 * @param stack The stack to be rotated.
 * @return TRUE if the rotation was successful, FALSE otherwise.
*/
static int	ft_rotate_a(t_stack *stack)
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
 * @brief Shift up all elements of stack b by 1. The first element becomes 
 * the last one.
 * @param stack The stack to be rotated.
 * @return TRUE if the rotation was successful, FALSE otherwise.
*/
static int	ft_rotate_b(t_stack *stack)
{
	int	tmp;
	int	i;
	int	count;

	count = 0;
	if (stack->size > 1)
	{
		tmp = stack->stack[stack->size - 1];
		i = stack->size - 1;
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
 * @brief Triggers up shift rotation functions.
 * @param stack The stack to be rotated.
 * @param op The operation to be performed (ra, rb, rr).
 * @return Void.
*/
void	ft_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate op)
{
	int	response_a;
	int	response_b;

	if (op == RA)
	{
		if (ft_rotate_a(stack_a))
			write(1, "ra\n", 3);
	}
	else if (op == RB)
	{
		if (ft_rotate_b(stack_b))
			write(1, "rb\n", 3);
	}
	else
	{
		response_a = ft_rotate_a(stack_a);
		response_b = ft_rotate_b(stack_b);
		if (response_a && response_b)
			write(1, "rr\n", 3);
		else if (response_a)
			write(1, "ra\n", 3);
		else if (response_b)
			write(1, "rb\n", 3);
	}
}
