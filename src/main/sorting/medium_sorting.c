/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 23:54:29 by proberto          #+#    #+#             */
/*   Updated: 2021/11/11 21:14:34 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Function that organizes a stack with up to 5 elements.
 * @details First the 2 smallest numbers are obtained, which are put into 
 * stack b, then a soft sort function is called to sort the rest of the stack,
 * and then the numbers that were in stack b are pushed back to stack a.
 * @param stack_a The stack to be sorted.
 * @param stack_b Auxiliary stack in the organization.
 * @return Void.
*/
void	ft_medium_sorting(t_stack *stack_a, t_stack *stack_b)
{
	int	top;
	int	len;
	int	smallest;

	len = stack_a->size;
	top = stack_a->top;
	smallest = ft_get_smallest(stack_a->array, len, top, LLONG_REF);
	smallest = ft_get_smallest(stack_a->array, len, top, smallest);
	while (stack_a->size > 3)
	{
		if (stack_a->array[stack_a->top] <= smallest)
			ft_push_b(stack_b, stack_a);
		else
			ft_rotate(stack_a, stack_b, RA);
	}
	ft_soft_sorting(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
	ft_push_a(stack_a, stack_b);
	if (stack_a->array[stack_a->top] > stack_a->array[stack_a->top + 1])
		ft_swap(stack_a, stack_b, SA);
}
