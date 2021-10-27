/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:52:38 by proberto          #+#    #+#             */
/*   Updated: 2021/10/27 00:35:36 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

# define TRUE 1
# define FALSE 0

int		are_there_elements_that_are_not_integers(int argc, char **argv);
int		are_there_elements_that_are_larger_than_an_integer(long long res,
			int argc, char **argv, char **aux);
int		are_there_duplicates(int *stack, int size);
int		num_elements(int argc, char **argv);
void	init_stack(int *stack, int len, char **argv);

#endif
