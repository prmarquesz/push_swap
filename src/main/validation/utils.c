/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:35:48 by proberto          #+#    #+#             */
/*   Updated: 2021/11/10 23:35:56 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	num_elements(int argc, char **argv)
{
	char	**aux;
	int		i;
	int		len;

	len = 0;
	while (--argc)
	{
		aux = ft_split(*(++argv), ' ');
		i = 0;
		while (aux[i++])
			len++;
		free(*aux);
	}
	return (len);
}

void	init_stack(int *stack, int len, char **argv)
{
	char	**aux;
	int		count;
	int		i;

	count = 0;
	while (count < len)
	{
		aux = ft_split(*(++argv), ' ');
		i = 0;
		while (aux[i])
		{
			stack[count++] = ft_atoi(aux[i++]);
		}
		free(*aux);
	}
}
