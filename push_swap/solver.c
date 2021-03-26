/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:12:01 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/25 23:39:35 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float	ft_sqrt(int nb)
{
	float	result;
	int		i;

	i = 0;
	result = 1;
	while (i < 1000)
	{
		result = (result + (nb / result)) / 2;
		i++;
	}
	return (result);
}

int 	get_quantile_number(int nbr)
{
	float quantile_size;

	if (!nbr)
		return(nbr);
	quantile_size = ft_sqrt(nbr) / 2;
	if (quantile_size >= (float)(int)quantile_size + 0.5)
		return((int)quantile_size + 1);
	else
		return((int)quantile_size);
}

void	goto_val(t_stack **s, int val, char stack_id)
{
	int	val_pos;
	int	i;

	val_pos = 0;
	while((*s)->value != val)
	{
		*s = (*s)->next;
		val_pos++;
	}
	if (val_pos <= stack_length(*s) - val_pos)
	{
		i = val_pos;
		while (--i >= 0)
		{
			rotate(s);
			printf("r%c\n", stack_id);
		}
	}
	else
	{
		i = stack_length(*s) - val_pos;
		while (--i >= 0)
		{
			reverse_rotate(s);
			printf("rr%c\n", stack_id);
		}
	}
}

int		quantile(t_stack *sorted, int val, int length, int quantile_size)
{
	int i;

	i = 0;
	while (sorted->value != val)
	{
		i++;
		sorted = sorted->next;
	}
	return (i / quantile_size);
}

void	push_a_to_b(t_stack **a, t_stack **b, t_stack *sorted, int chunk_number)
{
	int current_quantile_completion;
	int current_quantile;
	int total_length;

	current_quantile_completion = 0;
	current_quantile = 0;
	total_length = stack_length(*a);
	while (*a)
	{
		printf("%d/%d\n", total_length, chunk_number);
		if (quantile(sorted, (*a)->value, total_length, total_length / chunk_number) == current_quantile)
		{
			current_quantile_completion++;
			push(b, a);
			printf("pb\n");
		}
		else
		{
			rotate(a);
			printf("ra\n");
		}
		if (current_quantile_completion == total_length / chunk_number)
		{
			current_quantile++;
			current_quantile_completion = 0;
		}
	}
}

void	solver3(t_stack *a, t_stack *b)
{
	int		chunk_number;
	t_stack	*sorted_stack;

	chunk_number = get_quantile_number(stack_length(a));
	sorted_stack = clone_stack(a);
	sort_stack(sorted_stack);
	push_a_to_b(&a, &b, sorted_stack, chunk_number);
}