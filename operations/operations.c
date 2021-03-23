/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 00:21:35 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 12:14:13 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (b && *b)
	{
		tmp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = tmp;
	}
}

void	rotate(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->next = *s;
		*s = (*s)->next;
		tmp->next->next = NULL;
	}
}

void	reverse_rotate(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	while (tmp && tmp->next->next)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->next->next = (*s);
		(*s) = tmp->next;
		tmp->next = NULL;
	}
}

int 	check(t_stack *s, t_stack *b)
{
	if (b)
		return (0);
	if (!s->next)
		return (1);
	if (s->value < s->next->value)
		return (check(s->next, b));
	return (0);
}