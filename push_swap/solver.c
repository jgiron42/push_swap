/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:12:01 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 17:00:49 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_array(int array[3], t_stack *s)
{
	array[0] = (s->value < s->next->value) * (2 - (s->value < s->next->next->value)) + (s->value > s->next->value) * (3 - (s->value < s->next->next->value));
	array[1] = (s->next->value < s->value) * (2 - (s->next->value < s->next->next->value)) + (s->value < s->next->value) * (3 - (s->next->value < s->next->next->value));
	array[2] = (s->next->next->value < s->next->value) * (2 - (s->next->next->value < s->next->value)) + (s->next->next->value > s->next->value) * (3 - (s->next->next->value < s->next->value));
}

void 	sort3(t_stack **s, char stack_id)
{
	int	array[3];

	get_array(array, *s);
	if (array[0] == 1 && array[1] == 3)
	{
		rotate(s);
		printf("r%c\n", stack_id);
		swap(s);
		printf("s%c\n", stack_id);
		reverse_rotate(s);
		printf("rr%c\n", stack_id);
	}
	else if (array[0] == 2)
	{
		if (array[1] == 3)
		{
			reverse_rotate(s);
			printf("rr%c\n", stack_id);
		}
		else
		{
			swap(s);
			printf("s%c\n", stack_id);
		}
	}
	else if (array[0] == 3)
	{
		if (array[1] == 1)
		{
			rotate(s);
			printf("r%c\n", stack_id);
		}
		else
		{
			rotate(s);
			printf("r%c\n", stack_id);
			swap(s);
			printf("s%c\n", stack_id);
		}
	}
}

void	sort5(t_stack **a, t_stack **b)
{
	int i;

	while (stack_length(*a) > 3)
	{
		push(b, a);
		printf("pb\n");
	}
	sort3(a, 'a');
	i = 0;
	while (*b)
	{
		if ((*b)->value < (*a)->value || i % (3 + !((*b)->next)) == 0)
		{
			if ((*b)->value > (*a)->value)
			{
				i %= 3+ !((*b)->next);
				push(a, b);
				printf("pa\n");
				rotate(a);
				printf("ra\n");
			}
			else
			{
				push(a, b);
				printf("pa\n");
			}
		}
		else
		{
			rotate(a);
			printf("ra\n");
			i++;
		}
	}
	while (--i >= 0)
	{
		reverse_rotate(a);
		printf("rra\n");
	}
}

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

int		get_pos(t_stack **s, int val, int i)
{
	if (!*s)
		return (0);
	if ((*s)->value == val)
		return(i);
	rotate(s);
	i = get_pos(s, val, i + 1);
	reverse_rotate(s);
	return (i);
}

void	goto_val(t_stack **s, int val, char stack_id)
{
	int		val_pos;
	int		i;

	val_pos = get_pos(s, val, 0);
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
	while (sorted && sorted->value != val)
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

void	push_quantiles_to_a(t_stack **a, t_stack **b, t_stack *sorted, int chunk_number)
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
		sort3(&a, 'a');
	else if (stack_length(a) == 5)
		sort5(&a, &b);
	else
	{
		chunk_number = get_quantile_number(stack_length(a));
		sorted_stack = clone_stack(a);
		sort_stack(sorted_stack);
		push_a_to_b(&a, &b, sorted_stack, chunk_number);
		push_quantiles_to_a(&a, &b, sorted_stack, chunk_number);
	}
}