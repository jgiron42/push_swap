/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:07:09 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 16:12:45 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "checker.h"

int 	atoi_element(int *dst, char *str)
{
	long int ret;

	ret = 0;
	if (!str || !*str)
		return (1);
	*dst = 1;
	if (*str == '-')
		*dst = -1;
	else
		str--;
	while (*++str && *str != ' ')
		if (*str < '0' || *str > '9' ||
		ret * 10 + *str + 48 > (long int)INT_MAX + (*dst < 0))
			return (1);
		else
			ret = ret * 10 + *str - 48;
	*dst = (int)((long int)*dst * ret);
	return (0);
}

void 	free_stack(t_stack *stack)
{
	if (stack && stack->next)
		free_stack(stack->next);
	free(stack);
}

int 	add_element(t_stack **stack, char *element)
{
	t_stack	*tmp;

	tmp = &(t_stack){.prev = NULL, .next=*stack};
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_stack))))
		exit(1);
	tmp->next->next = NULL;
	if (!*stack)
		*stack = tmp->next;
	if (atoi_element(&tmp->next->value, element))
	{
		write(2, "Error\n", 6);
		free_stack(*stack);
		return (-1);
	}
	return (0);
}

t_stack *parse(int argc, char **argv)
{
	t_stack *ret;
	int		i;

	ret = NULL;
	i = -1;
//	while (++i < argc)
//		if (add_element(&ret, argv[i]) == -1)
//			return (NULL);
	while (argv[1][++i])
		if ((i == 0 || argv[1][i] == ' ') && add_element(&ret, argv[1] + i + (argv[1][i] == ' ')))
			return (NULL);
	return (ret);
}