/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:55:21 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/28 15:33:45 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		compute2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (cmp(line, "rr"))
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

int		compute(t_stack **stack_a, t_stack **stack_b, char *line)
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
	else
		return (compute2(stack_a, stack_b, line));
	return (0);
}

int		wait_for_instruction(char **line, t_stack *stack_a, t_stack *stack_b)
{
	while (get_next_line(0, line, 0))
	{
		if (*line && **line && compute(&stack_a, &stack_b, *line))
		{
			free(*line);
			free_stack(stack_a);
			free_stack(stack_b);
			return (1);
		}
		free(*line);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc == 1)
		return (0);
	if (!(stack_a = parse(argc, argv)))
	{
		free_stack(stack_a);
		return (1);
	}
	stack_b = NULL;
	if (wait_for_instruction(&line, stack_a, stack_b))
		return (1);
	free(line);
	printf(check(stack_a, stack_b) ? "OK\n" : "KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
}
