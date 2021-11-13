/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extremely_hard_sorting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 00:22:27 by proberto          #+#    #+#             */
/*   Updated: 2021/11/13 00:37:14 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Function that pushes the smallest elements from stack a to stack b.
 * @param stack_a The stack to be sorted.
 * @param stack_b Auxiliary stack in the organization.
 * @return Void.
*/
static void	ft_push_smaller_half_on_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	long long	middle;
	int			i;
	int			times;

	times = 1;
	middle = LLONG_REF;
	while (times < 10)
	{
		i = 0;
		while (i++ < stack_a->len / 10)
			middle = ft_get_smallest(
					stack_a->array,
					stack_a->len,
					stack_a->top,
					middle);
		while (stack_b->size < stack_a->len / 10 * times)
		{
			if (stack_a->array[stack_a->top] <= middle)
				ft_push_b(stack_b, stack_a);
			else
				ft_rotate(stack_a, stack_b, RA);
		}
		times++;
	}
}

/**
 * @brief Function that pushes the largest elements from stack a to stack b.
 * @param stack_a The stack to be sorted.
 * @param stack_b Auxiliary stack in the organization.
 * @return Void.
*/
static void	ft_push_bigger_half_on_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 2)
		ft_push_b(stack_b, stack_a);
	if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top + 1])
		ft_swap(stack_a, stack_b, SA);
	if (stack_b->array[stack_b->size - 1] < stack_a->array[stack_a->top])
		ft_push_a(stack_a, stack_b);
	else if (stack_b->array[stack_b->size - 1]
		< stack_a->array[stack_a->top + 1])
	{
		ft_push_a(stack_a, stack_b);
		ft_swap(stack_a, stack_b, SA);
	}
	else
	{
		ft_push_a(stack_a, stack_b);
		ft_rotate(stack_a, stack_b, RA);
	}
	ft_update_stack_config(stack_a);
}

/**
 * @brief Function that organizes a stack with more than 100 elements.
 * @details First, the smaller half of stack a is pushed to stack b, then the 
 * other (larger) half is also pushed to stack b, leaving only one element in 
 * stack a. Then all the elements from stack b are pushed back to stack a, but 
 * they will now fit neatly into the stack. Finally, stack a is rotated until 
 * the stack is sorted in ascending order (smallest number at the top of the 
 * stack, highest number at the end).
 * @param stack_a The stack to be sorted.
 * @param stack_b Auxiliary stack in the organization.
 * @return Void.
*/
void	ft_extremely_hard_sorting(t_stack *stack_a, t_stack *stack_b)
{
	ft_push_smaller_half_on_stack_b(stack_a, stack_b);
	ft_push_bigger_half_on_stack_b(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		ft_sorting(stack_a, stack_b);
	}
	while (ft_is_sorted(stack_a->array, stack_a->top, stack_a->len) == FALSE)
	{
		if (stack_a->smaller <= stack_a->size / 2)
			ft_rotate(stack_a, stack_b, RA);
		else
			ft_reverse_rotate(stack_a, stack_b, RA);
	}
}
