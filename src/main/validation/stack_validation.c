/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 00:32:40 by proberto          #+#    #+#             */
/*   Updated: 2021/11/13 02:14:16 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Validates the input string (subfunction).
*/
static int	validate_formatting_and_type(char **aux, int i, int j)
{
	if (!ft_isdigit(aux[i][j]) && aux[i][j] != '-')
	{
		free(*aux);
		free(aux);
		return (TRUE);
	}
	else if (aux[i][j] == '-' && j > 0)
	{
		free(*aux);
		free(aux);
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Validates the input string.
 * @details Function that checks if there are only numbers on the stack.
 * @param argc The arguments number.
 * @param argv The arguments array.
 * @return TRUE if there are characters other than numbers/digits,
 * FALSE if there are only numbers.
*/
int	there_are_elements_that_are_not_int(int argc, char **argv)
{
	char	**aux;
	int		i;
	int		j;

	while (--argc)
	{
		i = 0;
		aux = ft_split(*(++argv), ' ');
		if (*aux == NULL)
			return (TRUE);
		while (aux[i])
		{
			j = 0;
			while (aux[i][j])
			{
				if (validate_formatting_and_type(aux, i, j))
					return (TRUE);
				j++;
			}
			free(aux[i]);
			i++;
		}
		free(aux);
	}
	return (FALSE);
}

/**
 * @brief Auxiliary function that assigns a negative number to the sign 
 * parameter if there is a '-' flag.
 * @param c The character to be checked.
 * @param j The index of the character.
 * @param sign The sign parameter.
 * @return Parameter j incremented or not.
*/
static int	ft_signal_control(char c, int j, int *sign)
{
	if (c == '-')
		*sign = -1;
	if (c == '-' || c == '+')
		j++;
	return (j);
}

/**
 * @brief Validates the input string.
 * @details Function that checks for numbers greater than integers (INT_MAX /
 * INT_MIN).
 * @param res Auxiliary variable.
 * @param argc The arguments array.
 * @param argv The arguments array.
 * @param aux Auxiliary variable.
 * @return TRUE if there are numbers greater than integers, FALSE otherwise.
*/
int	there_are_elements_that_are_larger_than_an_int(long long res, int argc,
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
			j = ft_signal_control(aux[i][j], j, &sign);
			while (aux[i][j])
				res = res * 10 + (aux[i][j++] - '0');
			if ((res * sign) < INT_MIN || (res * sign) > INT_MAX)
				return (TRUE);
			free(aux[i]);
		}
		free(aux);
	}
	return (FALSE);
}

/**
 * @brief Validates the input string.
 * @details Function that checks if there are duplicated numbers.
 * @param stack The array stack to be checked.
 * @param size The size of the stack array.
 * @return TRUE if there are duplicated numbers, FALSE otherwise.
*/
int	there_are_duplicates(int *stack, int size)
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
