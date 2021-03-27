/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:06:19 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 22:25:57 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		max_element(t_stack *a)
{
	int	ret;

	ret = INT32_MIN;
	while (a)
	{
		if (a->value > ret)
			ret = a->value;
		a = a->next;
	}
	return (ret);
}

int		min_element(t_stack *a)
{
	long int	ret;

	ret = LONG_MAX;
	while (a)
	{
		if (a->value < ret)
			ret = a->value;
		a = a->next;
	}
	return ((int)ret);
}

int		next_val(t_stack *s, int val)
{
	long int	ret;
	t_stack		*tmp;

	ret = LONG_MAX;
	tmp = s;
	while (s)
	{
		if (s->value < ret && s->value > val)
			ret = s->value;
		s = s->next;
	}
	if (ret == LONG_MAX)
	{
		return (min_element(tmp));
	}
	return ((int)ret);
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

int		get_quantile_number(int nbr)
{
	float	quantile_size;

	if (!nbr)
		return (nbr);
	quantile_size = ft_sqrt(nbr) / 2;
	if (quantile_size >= (float)(int)quantile_size + 0.5)
		return ((int)quantile_size + 1);
	else
		return ((int)quantile_size);
}
