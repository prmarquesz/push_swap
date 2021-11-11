/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:42:42 by proberto          #+#    #+#             */
/*   Updated: 2021/11/08 13:10:02 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Take the first element at the top of b and put it at the top of a. Do 
 * nothing if b is empty
 * @return Void 
*/
void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 0)
	{
		stack_a->array[--stack_a->top] = stack_b->array[--stack_b->size];
		stack_b->array[stack_b->size] = 0;
		stack_a->size++;
		write(1, "pa\n", 3);
	}
}

/**
 * @brief Take the first element at the top of a and put it at the top of b. Do 
 * nothing if b is empty
 * @return Void 
*/
void	ft_push_b(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_a->size > 0)
	{
		stack_b->array[stack_b->size++] = stack_a->array[stack_a->top];
		stack_a->array[stack_a->top++] = 0;
		stack_a->size--;
		write(1, "pb\n", 3);
	}
}
