/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:59:30 by proberto          #+#    #+#             */
/*   Updated: 2021/11/12 23:48:04 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static	void	ft_play(t_stack *stacka, t_stack *stackb)
{
	if (stacka->len > 1
		&& !ft_is_sorted(stacka->array, stacka->top, stacka->len))
	{
		if (stacka->len <= 3)
			ft_soft_sorting(stacka, stackb);
		else if (stacka->len <= 5)
			ft_medium_sorting(stacka, stackb);
		else if (stacka->len <= 100)
			ft_hard_sorting(stacka, stackb);
		else
			ft_extremely_hard_sorting(stacka, stackb);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stacka;
	t_stack	stackb;
	char	**aux;

	aux = NULL;
	if (there_are_elements_that_are_not_int(argc, argv)
		|| there_are_elements_that_are_larger_than_an_int(0, argc, argv, aux))
	{
		free(aux);
		exit(ft_error());
	}
	init_stack(&stacka, &stackb, argc, argv);
	if (there_are_duplicates(stacka.array, stacka.len))
	{
		free(aux);
		exit(ft_error());
	}
	ft_play(&stacka, &stackb);
	ft_free_stacks(&stacka, &stackb);
	return (0);
}
