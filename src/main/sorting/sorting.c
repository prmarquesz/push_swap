/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:31:19 by proberto          #+#    #+#             */
/*   Updated: 2021/11/13 13:30:00 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Function that searches from top to bottom for the best fit of the 
 * number at the top of the stack b.
 * @param stack The stack to be sorted.
 * @return Void.
*/
static void	ft_look_for_top_down_fit(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	i;

	count = 0;
	i = stack_a->top;
	while (i <= stack_a->larger)
	{
		if (stack_b->array[stack_b->size - 1] > stack_a->array[i++])
			count++;
	}
	if (count <= stack_a->size / 2)
	{
		while (count-- > 0)
			ft_rotate(stack_a, stack_b, RA);
	}
	else
	{
		count = stack_a->size - count;
		while (count-- > 0)
			ft_reverse_rotate(stack_a, stack_b, RRA);
	}
	ft_push_a(stack_a, stack_b);
}

/**
 * @brief Function that searches from bottom to top for the best fit of the 
 * number at the top of the stack b.
 * @param stack The stack to be sorted.
 * @return Void.
*/
static void	ft_look_for_bottom_up_fit(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	i;

	count = 0;
	i = stack_a->len - 1;
	while (i >= stack_a->smaller)
	{
		if (stack_b->array[stack_b->size - 1] < stack_a->array[i--])
			count++;
	}
	if (count <= stack_a->size / 2)
	{
		while (count-- > 0)
			ft_reverse_rotate(stack_a, stack_b, RRA);
	}
	else
	{
		count = stack_a->size - count;
		while (count-- > 0)
			ft_rotate(stack_a, stack_b, RA);
	}
	ft_push_a(stack_a, stack_b);
}

/**
 * @brief Function that looks for the best fit of the number located at the top 
 * of stack b, in stack a.
 * @param stack The stack to be sorted.
 * @return Void.
*/
static void	ft_to_fit_in(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->array[stack_b->size - 1] > stack_a->array[stack_a->len - 1]
		&& stack_a->sorted == TRUE)
	{
		ft_push_a(stack_a, stack_b);
		ft_rotate(stack_a, stack_b, RA);
		return ;
	}
	else if (stack_b->array[stack_b->size - 1] > stack_a->array[stack_a->top])
		ft_look_for_top_down_fit(stack_a, stack_b);
	else
		ft_look_for_bottom_up_fit(stack_a, stack_b);
}

/**
 * @brief Function that sorts the stack.
 * @param stack The stack to be sorted.
 * @return Void.
*/
void	ft_sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->array[stack_b->size - 1] < stack_a->array[stack_a->top])
	{
		if (stack_b->array[stack_b->size - 1]
			> stack_a->array[stack_a->len - 1])
			ft_push_a(stack_a, stack_b);
		else
			ft_to_fit_in(stack_a, stack_b);
	}
	else if (stack_b->array[stack_b->size - 1]
		< stack_a->array[stack_a->top + 1])
	{
		ft_push_a(stack_a, stack_b);
		if (stack_b->size > 1 && stack_b->array[stack_b->size - 2]
			> stack_b->array[stack_b->size - 1])
			ft_swap(stack_a, stack_b, SS);
		else
			ft_swap(stack_a, stack_b, SA);
	}
	else
		ft_to_fit_in(stack_a, stack_b);
	ft_update_stack_config(stack_a);
}
