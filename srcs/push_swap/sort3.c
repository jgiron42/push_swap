/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:53:35 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 22:22:21 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_array(int array[3], t_stack *s)
{
	array[0] = (s->value < s->next->value) * (2 -
(s->value < s->next->next->value)) + (s->value > s->next->value) *
(3 - (s->value < s->next->next->value));
	array[1] = (s->next->value < s->value) * (2 -
(s->next->value < s->next->next->value)) + (s->value < s->next->value) *
(3 - (s->next->value < s->next->next->value));
	array[2] = (s->next->next->value < s->next->value) * (2 -
(s->next->next->value < s->next->value)) +
(s->next->next->value > s->next->value) *
(3 - (s->next->next->value < s->next->value));
}

void	sort3_2(t_stack **s, int array[3], char stack_id, char stack_id2)
{
	if (array[0] == 3)
	{
		if (array[1] == 1)
		{
			rotate(s);
			printf("r%c\n", stack_id2);
		}
		else
		{
			rotate(s);
			printf("r%c\n", stack_id2);
			swap(s);
			printf("s%c\n", stack_id);
		}
	}
	else if (stack_id != stack_id2)
		printf("rb\n");
}

void	sort3(t_stack **s, char stack_id, char stack_id2)
{
	int	array[3];

	get_array(array, *s);
	if (array[0] == 1 && array[1] == 3)
	{
		rotate(s);
		printf("r%c\n", stack_id2);
		swap(s);
		printf("s%c\n", stack_id);
		reverse_rotate(s);
		printf("rr%c\n", stack_id);
	}
	else if (array[0] == 2 && array[1] == 3)
	{
		reverse_rotate(s);
		printf("rr%c\n", stack_id2);
	}
	else if (array[0] == 2 && array[1] != 3)
	{
		swap(s);
		stack_id2 = stack_id2 == 'r' ? 's' : stack_id2;
		printf("s%c\n", stack_id2);
	}
	else
		sort3_2(s, array, stack_id, stack_id2);
}
