/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:44:25 by proberto          #+#    #+#             */
/*   Updated: 2021/11/09 11:07:02 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Function that return the smaller number of the stack.
 * @param array The array of numbers.
 * @param len The length of the array.
 * @param i The initial index.
 * @return The smaller number of the stack.
*/
static int	ft_get_smaller(int *array, int len, int i)
{
	int	smallest;

	smallest = INT_MAX;
	while (i < len)
	{
		if (array[i] <= smallest)
			smallest = array[i];
		i++;
	}
	return (smallest);
}

/**
 * @brief Function that analyzes the stack and returns the best operation to
 * perform to sort the stack.
 * @param stack The stack to be analyzed.
 * @return The best operation to perform.
*/
static int	ft_parsing(t_stack *stack)
{
	int	smallest;

	smallest = ft_get_smaller(stack->array, stack->size, 0);
	if (smallest == stack->array[stack->top])
		return (REVERSE);
	else if (smallest == stack->array[stack->top + 1])
	{
		if (stack->array[stack->top] < stack->array[stack->top + 2])
			return (SWAP);
		else
			return (ROTATE);
	}
	else
	{
		if (stack->array[stack->top] < stack->array[stack->top + 1])
			return (REVERSE);
		else
			return (SWAP);
	}
	return (FALSE);
}

/**
 * @brief Function that performs stack ordering operations.
 * @param stack The stack to be sorted.
 * @param operation The operation to be performed.
*/
static void	ft_play(t_stack *stack_a, t_stack *stack_b, int operation)
{
	if (operation == SWAP)
		ft_swap(stack_a, stack_b, SA);
	else if (operation == ROTATE)
		ft_rotate(stack_a, stack_b, RA);
	else if (operation == REVERSE)
		ft_reverse_rotate(stack_a, stack_b, RRA);
}

/**
 * @brief Function that organizes a stack with up to 3 elements.
 * @details As long as the stack is unordered, the stack is submitted to 
 * the parsing function, which returns the operation to be performed, by 
 * Finally, once we have the required operation, it's called the play function.
 * @param stack_a The stack to be sorted.
 * @param stack_b Auxiliary stack in the organization.
 * @return Void.
*/
void	ft_soft_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	operation;

	operation = 0;
	while (ft_is_sorted(stack_a->array, stack_a->top, stack_a->len) == FALSE)
	{
		if (stack_a->len == 2)
		{
			ft_swap(stack_a, stack_b, SA);
			return ;
		}
		operation = ft_parsing(stack_a);
		ft_play(stack_a, stack_b, operation);
	}
}
