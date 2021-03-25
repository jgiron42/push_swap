/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:12:01 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/25 17:24:25 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_sqrt(int nb)
{
	float	result;
	float 	tmp;
	int		i;

	i = 0;
	tmp = 0;
	result = 1;
	while (tmp != result)
	{
		tmp = result;
		result = (result + (nb / result)) / 2;
		i++;
	}
	return (result);
}

int 	get_chunk_size(int nbr)
{
	float chunk_size;

	chunk_size = ft_sqrt(nbr) / 2;
	if (chunk_size >= (int)chunk_size + 0.5)
		return((int)chunk_size + 1);
	else
		return((int)chunk_size);
}

void	solver3(t_stack *a, t_stack *b)
{
	int chunk_size;

	chunk_size = get_chunk_size()
}