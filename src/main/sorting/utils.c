/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 00:19:38 by proberto          #+#    #+#             */
/*   Updated: 2021/11/10 11:54:59 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/**
 * @brief Function that checks if the stack array is sorted.
 * @param array The array to be checked.
 * @param i The inital index of the array.
 * @param len The length of the array.
 * @return TRUE if the array is sorted, FALSE otherwise.
*/
int	ft_is_sorted(int *array, int i, int len)
{
	while (i < len - 1)
	{
		if (array[i] > array[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @brief Function that find the smallest element in the array.
 * @param array The stack array to be searched.
 * @param len The length of the array.
 * @param i The initial index of the array.
 * @param ref The reference element (serves as a reference to get a second, 
 * third, or fourth smallest number and so on).
 * @return The smallest element in the array.
*/
int	ft_get_smallest(int *array, int len, int i, int ref)
{
	int	smallest;

	smallest = 2147483647;
	while (i < len)
	{
		if (array[i] < smallest && array[i] > ref)
			smallest = array[i];
		i++;
	}
	return (smallest);
}

/**
 * @brief Function that finds the index of the smallest number in the array.
 * @param array The stack array to be searched.
 * @param i The initial index of the array.
 * @param len The length of the array.
 * @return The index of the smallest number in the array.
*/
int	ft_get_smallest_index(int *array, int i, int len)
{
	int	smaller;
	int	index;

	smaller = INT_MAX;
	index = 0;
	while (i < len)
	{
		if (array[i] <= smaller)
		{
			smaller = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

/**
 * @brief Function that find the biggest element in the array.
 * @param array The stack array to be searched.
 * @param len The length of the array.
 * @param i The initial index of the array.
 * @param ref The reference element (serves as a reference to get a second, 
 * third, or fourth smallest number and so on).
 * @return The biggest element in the array.
*/
int	ft_get_biggest(int *array, int len, int i, int ref)
{
	int	bigger;

	bigger = INT_MIN;
	while (i < len)
	{
		if (array[i] >= bigger)
			bigger = array[i];
		i++;
	}
	return (bigger);
}

/**
 * @brief Function that finds the index of the biggest number in the array.
 * @param array The stack array to be searched.
 * @param i The initial index of the array.
 * @param len The length of the array.
 * @return The index of the biggest number in the array.
*/
int	ft_get_biggest_index(int *array, int i, int len)
{
	int	larger;
	int	index;

	larger = INT_MIN;
	index = 0;
	while (i < len)
	{
		if (array[i] >= larger)
		{
			larger = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}
