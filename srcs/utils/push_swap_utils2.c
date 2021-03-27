/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:07:22 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 22:26:21 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_pos(t_stack **s, int val, int i)
{
	if (!*s)
		return (0);
	if ((*s)->value == val)
		return (i);
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

int		quantile(t_stack *sorted, int val, int quantile_size)
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

int		stack_length(t_stack *s)
{
	int ret;

	ret = s && s->next;
	while (s && s->next)
	{
		s = s->next;
		ret++;
	}
	return (ret);
}
