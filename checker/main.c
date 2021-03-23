/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:55:21 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 17:00:59 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int 	compute(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (cmp(line, "sa"))
		swap(stack_a);
	else if (cmp(line, "sb"))
		swap(stack_b);
	else if (cmp(line, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (cmp(line, "pa"))
		push(stack_a, stack_b);
	else if (cmp(line, "pb"))
		push(stack_b, stack_a);
	else if (cmp(line, "ra"))
		rotate(stack_a);
	else if (cmp(line, "rb"))
		rotate(stack_b);
	else if (cmp(line, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (cmp(line, "rra"))
		reverse_rotate(stack_a);
	else if (cmp(line, "rrb"))
		reverse_rotate(stack_b);
	else if (cmp(line, "rrr"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (!(stack_a = parse(argc, argv)))
		return (1);
	stack_b = NULL;
	while (get_next_line(0, &line))
	{
		if (line && *line && compute(&stack_a, &stack_b, line))
			break ;
//		print_stack(stack_a, stack_b);
	}
	printf("%s\n", (char *)(check(stack_a, stack_b) * (intptr_t)"OK" + !check(stack_a, stack_b) * (intptr_t)"KO"));
}