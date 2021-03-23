/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:56:25 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 12:11:28 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include "string.h"
#include "strings.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

typedef struct	s_stack
{
	int 			value;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

# define BUFFER_SIZE 10
# define NAME "push_swap"

t_stack	*parse(int args, char **argv);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strjoinf1(char *s1, char *s2);
int		get_next_line(int fd, char **line);
int		cmp(char *s1, char *s2);
void 	free_stack(t_stack *stack);

void	swap(t_stack **stack);
void	push(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **s);
void	rotate(t_stack **s);
void	print_stack(t_stack *a, t_stack *b);
int 	check(t_stack *s, t_stack *b);

#endif
