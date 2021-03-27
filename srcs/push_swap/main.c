/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:01:50 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 22:11:43 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack(t_stack *s)
{
	int	is_sorted;
	int i;
	int len_a;

	i = 0;
	len_a = stack_length(s);
	is_sorted = 1;
	while (s && s->next)
	{
		if (i % len_a == len_a - 1)
		{
			if (is_sorted)
				break ;
			is_sorted = 1;
		}
		else if (s->value > s->next->value && i % len_a != len_a - 1)
		{
			swap(&s);
			is_sorted = 0;
		}
		rotate(&s);
		i++;
	}
	while (s->value > get_last(s)->value)
		reverse_rotate(&s);
}

t_stack	*get_last(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!(stack_a = parse(argc, argv)))
	{
		free_stack(stack_a);
		return (1);
	}
	stack_b = NULL;
	solver3(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
