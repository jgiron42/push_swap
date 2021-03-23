/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:55:21 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 01:33:07 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int 	compute(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (cmp(line, "sa\n"))
		swap(stack_a);
	else if (cmp(line, "sb\n"))
		swap(stack_b);
	else if (cmp(line, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (cmp(line, "pa\n"))
		push(stack_a, stack_b);
	else if (cmp(line, "pb\n"))
		push(stack_b, stack_a);
	else if (cmp(line, "ra\n"))
		rotate(stack_a);
	else if (cmp(line, "rb\n"))
		rotate(stack_b);
	else if (cmp(line, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (cmp(line, "rra\n"))
		reverse_rotate(stack_a);
	else if (cmp(line, "rrb\n"))
		reverse_rotate(stack_b);
	else if (cmp(line, "rrr\n"))
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
	while (get_next_line(1, &line))
	{
		if (compute(&stack_a, &stack_b, line))
			break ;
		print_stack(stack_a, stack_b);
	}
	printf("%s", (char *)(check(*stack_a) * (intptr_t)"OK" + !check(*stack_a) * (intptr_t)"KO"));
}