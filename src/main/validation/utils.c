/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:35:48 by proberto          #+#    #+#             */
/*   Updated: 2021/11/12 23:46:06 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Function that displays error message.
 * @return 1 to exit in error.
*/
int	ft_error(void)
{
	ft_putendl_fd("Error", 1);
	return (1);
}

/**
 * @brief Function that counts the number of elements passed as arguments.
 * @param argc Number of arguments passed.
 * @param argv Array of arguments passed.
 * @return Number of elements.
*/
static int	num_elements(int argc, char **argv)
{
	char	**aux;
	int		i;
	int		len;

	len = 0;
	while (--argc)
	{
		aux = ft_split(*(++argv), ' ');
		if (*aux == NULL)
			exit(ft_error());
		i = 0;
		while (aux[i])
		{
			len++;
			free(aux[i++]);
		}
		free(aux);
	}
	return (len);
}

/**
 * @brief Function that does the initial configuration (top, length and size),
 * converting and copying the char array to the integer array.
 * @param stack Stack to be configured/started.
 * @param argc Number of arguments.
 * @param argv Array of arguments.
 * @return Void.
*/
void	init_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	char	**aux;
	int		count;
	int		i;

	stack_a->len = num_elements(argc, argv);
	stack_a->size = stack_a->len;
	stack_b->size = 0;
	stack_a->top = 0;
	stack_b->top = 0;
	stack_a->array = ft_calloc(stack_a->len, sizeof(int));
	stack_b->array = ft_calloc(stack_a->len, sizeof(int));
	if (stack_a->array == NULL || stack_b->array == NULL)
		exit(ft_error());
	count = 0;
	while (count < stack_a->len)
	{
		aux = ft_split(*(++argv), ' ');
		i = 0;
		while (aux[i])
		{
			stack_a->array[count++] = ft_atoi(aux[i]);
			free(aux[i++]);
		}
		free(aux);
	}
}

/**
 * @brief Function that frees the memory allocated to the stack.
*/
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
}
