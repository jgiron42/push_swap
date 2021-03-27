/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:55:07 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 21:55:07 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort5(t_stack **a, t_stack **b)
{
	while (stack_length(*a) > 3)
	{
		push(b, a);
		printf("pb\n");
	}
	if ((*b)->value > (*b)->next->value)
	{
		swap(b);
		sort3(a, 'a', 'r');
	}
	else
		sort3(a, 'a', 'a');
	while (*b)
	{
		goto_val(a, next_val(*a, (*b)->value), 'a');
		push(a, b);
		printf("pa\n");
	}
	goto_val(a, min_element(*a), 'a');
}
