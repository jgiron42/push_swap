/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:12:01 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 22:17:12 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a_to_b2(int chunk_number, int total_length,
	int *current_quantile_completion, int *current_quantile)
{
	if ((*current_quantile_completion) == total_length / chunk_number)
	{
		(*current_quantile)++;
		(*current_quantile_completion) = 0;
	}
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
		if (quantile(sorted, (*a)->value, total_length / chunk_number) ==
		current_quantile)
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
		push_a_to_b2(chunk_number, total_length, &current_quantile_completion,
		&current_quantile);
	}
}

void	push_quantiles_to_a(t_stack **a, t_stack **b, t_stack *sorted,
		int chunk_number)
{
	if (sorted->next)
		push_quantiles_to_a(a, b, sorted->next, chunk_number);
	goto_val(b, sorted->value, 'b');
	push(a, b);
	printf("pa\n");
}

void	solver3(t_stack *a, t_stack *b)
{
	int		chunk_number;
	t_stack	*sorted_stack;

	if (check(a, b))
		return ;
	if (stack_length(a) == 2)
		printf("sa\n");
	else if (stack_length(a) == 3)
		sort3(&a, 'a', 'a');
	else if (stack_length(a) == 5)
		sort5(&a, &b);
	else
	{
		chunk_number = get_quantile_number(stack_length(a));
		sorted_stack = clone_stack(a);
		sort_stack(sorted_stack);
		push_a_to_b(&a, &b, sorted_stack, chunk_number);
		push_quantiles_to_a(&a, &b, sorted_stack, chunk_number);
		free_stack(sorted_stack);
	}
}
