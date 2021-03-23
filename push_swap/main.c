/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:01:50 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 17:09:03 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_length(t_stack *s)
{
	int ret;

	ret = 0;
	while (s)
	{
		s = s->next;
		ret++;
	}
	return (ret);
}

t_stack	*get_last(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

void	solver1(t_stack *a, t_stack *b)
{
	int tmp;
	int	i;
	int len_a;

	i = 0;
//	tmp = get_last(a)->value;
	tmp = INT32_MAX;
	len_a = stack_length(a);
	while (++i <= len_a)
	{
		if (a->value < tmp)
		{
			tmp = a->value;
			push(&b, &a);
			printf("pb\n");
		}
		else
		{
			tmp = a->value;
			rotate(&a);
			printf("ra\n");
		}
//		print_stack(a, b);
	}
	while (a->value > get_last(a)->value)
	{
		rotate(&a);
		printf("ra\n");
	}
	i = 0;
	len_a = stack_length(a);
	while (b && i < 100)
	{
//			printf("%d\n", i %len_a);
		if (a->value > b->value && (get_last(a)->value < b->value || i % len_a == 0))
		{
			push(&a, &b);
			printf("pa\n");
			i = i % len_a;
			if (i)
				i++;
			len_a++;
		}
		else
		{
			reverse_rotate(&a);
			printf("rra\n");
			i++;
		}
//		print_stack(a, b);
	}
	while (a->value > get_last(a)->value)
	{
		reverse_rotate(&a);
		printf("rra\n");
	}
//	print_stack(a, b);
}

void 	solver2(t_stack *a, t_stack *b)
{
	int	is_sorted;
	int i;
	int len_a;

	i = 0;
	len_a = stack_length(a);
	is_sorted = 1;
	while (a && a->next)
	{
		if (i % len_a == len_a - 1)
		{
			if (is_sorted)
				break ;
			is_sorted = 1;
		}
		else if (a->value > a->next->value && i % len_a != len_a - 1)
		{
			swap(&a);
			printf("sa\n");
			is_sorted = 0;
		}
		rotate(&a);
		printf("ra\n");
		i++;
	}
	while (a->value > get_last(a)->value)
	{
		reverse_rotate(&a);
		printf("rra\n");
	}
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!(stack_a = parse(argc, argv)))
		return (1);
	stack_b = NULL;
	solver1(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}