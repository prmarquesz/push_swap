/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 23:52:38 by proberto          #+#    #+#             */
/*   Updated: 2021/11/13 00:33:37 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"

# define TRUE 1
# define FALSE 0
# define SWAP 5
# define PUSH 6
# define ROTATE 7
# define REVERSE 8
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LLONG_REF -2147483649

typedef enum e_swap {
	SA,
	SB,
	SS
}			t_swap;

typedef enum e_rotate {
	RA,
	RB,
	RR
}			t_rotate;

typedef enum e_reverse_rotate {
	RRA,
	RRB,
	RRR
}			t_reverse_rotate;

typedef struct s_stack {
	int	*array;
	int	size;
	int	len;
	int	top;
	int	smaller;
	int	larger;
	int	sorted;
}		t_stack;

int		ft_error(void);
int		there_are_elements_that_are_not_int(int argc, char **argv);
int		there_are_elements_that_are_larger_than_an_int(long long res,
			int argc, char **argv, char **aux);
int		there_are_duplicates(int *stack, int size);
void	init_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
void	ft_free_stacks(t_stack *stack_a, t_stack *stack_b);
void	ft_swap(t_stack *stack_a, t_stack *stack_b, t_swap op);
void	ft_push_a(t_stack *stack_a, t_stack *stack_b);
void	ft_push_b(t_stack *stack_b, t_stack *stack_a);
void	ft_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate op);
void	ft_reverse_rotate(t_stack *stack_a, t_stack *stack_b,
			t_reverse_rotate op);
void	ft_update_stack_config(t_stack *stack);
int		ft_is_sorted(int *array, int i, int len);
int		ft_get_smallest(int *array, int len, int i, long long ref);
int		ft_get_smallest_index(int *array, int i, int len);
int		ft_get_biggest_index(int *array, int i, int len);
void	ft_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_soft_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_medium_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_hard_sorting(t_stack *stack_a, t_stack *stack_b);
void	ft_extremely_hard_sorting(t_stack *stack_a, t_stack *stack_b);

#endif
