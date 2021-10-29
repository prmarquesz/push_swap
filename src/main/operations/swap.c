/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:35:35 by proberto          #+#    #+#             */
/*   Updated: 2021/10/28 22:32:26 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Swap the first 2 elements at the top of stack a.
 * @param stack The stack to swap.
 * @return TRUE if the swap was successful, FALSE otherwise.
*/
static int	ft_swap_a(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->stack[stack->top];
		stack->stack[stack->top] = stack->stack[stack->top + 1];
		stack->stack[stack->top + 1] = tmp;
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Swap the first 2 elements at the top of stack b.
 * @param stack The stack to swap.
 * @return TRUE if the swap was successful, FALSE otherwise.
*/
static int	ft_swap_b(t_stack *stack)
{
	int	tmp;

	if (stack->size > 1)
	{
		tmp = stack->stack[stack->size - 1];
		stack->stack[stack->size - 1] = stack->stack[stack->size - 2];
		stack->stack[stack->size - 2] = tmp;
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Trigger swap functions. 
 * @param stack The stack to swap.
 * @param op The operation to be performed (sa, sb, ss).
 * @return Void.
*/
void	ft_swap(t_stack *stack_a, t_stack *stack_b, t_swap op)
{
	int	response_a;
	int	response_b;

	if (op == SA)
	{
		if (ft_swap_a(stack_a))
			write(1, "sa\n", 3);
	}
	else if (op == SB)
	{
		if (ft_swap_b(stack_b))
			write(1, "sb\n", 3);
	}
	else
	{
		response_a = ft_swap_a(stack_a);
		response_b = ft_swap_b(stack_b);
		if (response_a && response_b)
			write(1, "ss\n", 3);
		else if (response_a)
			write(1, "sa\n", 3);
		else if (response_b)
			write(1, "sb\n", 3);
	}
}
