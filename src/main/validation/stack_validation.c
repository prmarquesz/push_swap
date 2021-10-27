/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:32:40 by proberto          #+#    #+#             */
/*   Updated: 2021/11/10 23:08:55 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static int	validate_formatting_and_type(char **aux, int i, int j)
{
	if (!ft_isdigit(aux[i][j]) && aux[i][j] != '-')
	{
		free(*aux);
		return (TRUE);
	}
	else if (aux[i][j] == '-' && j > 0)
	{
		free(*aux);
		return (TRUE);
	}
	return (FALSE);
}

int	are_there_elements_that_are_not_integers(int argc, char **argv)
{
	char	**aux;
	int		i;
	int		j;

	while (--argc)
	{
		i = 0;
		aux = ft_split(*(++argv), ' ');
		while (aux[i])
		{
			j = 0;
			while (aux[i][j])
			{
				if (validate_formatting_and_type(aux, i, j))
					return (TRUE);
				j++;
			}
			i++;
		}
		free(*aux);
	}
	return (FALSE);
}

int	are_there_elements_that_are_larger_than_an_integer(long long res, int argc,
char **argv, char **aux)
{
	int	i;
	int	j;
	int	sign;

	while (--argc)
	{
		aux = ft_split(*(++argv), ' ');
		i = -1;
		while (aux[++i])
		{
			sign = 1;
			res = 0;
			j = 0;
			if (aux[i][j] == '-')
				sign = -1;
			if (aux[i][j] == '-' || aux[i][j] == '+')
				j++;
			while (aux[i][j])
				res = res * 10 + (aux[i][j++] - '0');
			if ((res * sign) < INT_MIN || (res * sign) > INT_MAX)
				return (TRUE);
		}
		free(*aux);
	}
	return (FALSE);
}

int	are_there_duplicates(int *stack, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size)
	{
		aux = stack[i];
		j = 0;
		while (j < size)
		{
			if (i == j)
				j++;
			if (j < size && aux == stack[j++])
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
