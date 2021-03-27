/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:56:25 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/27 23:06:56 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include "string.h"
# include "strings.h"
# include "limits.h"
# include "stdio.h"
# include "stdlib.h"
# include "stdint.h"
# include "unistd.h"

typedef struct	s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

# define BUFFER_SIZE 10
# define NAME "push_swap"

t_stack			*parse(int args, char **argv);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoinf1(char *s1, char *s2);
int				get_next_line(int fd, char **line, int free_flag);
int				cmp(char *s1, char *s2);
void			free_stack(t_stack *stack);
int				stack_length(t_stack *s);
void			solver3(t_stack *a, t_stack *b);
t_stack			*clone_stack(t_stack *s);
t_stack			*get_last(t_stack *s);
t_stack			*parse(int args, char **argv);
void			sort_stack(t_stack *s);
void			goto_val(t_stack **s, int val, char stack_id);
void			sort3(t_stack **s, char stack_id, char stack_id2);
void			sort5(t_stack **a, t_stack **b);
int				get_pos(t_stack **s, int val, int i);
int				quantile(t_stack *sorted, int val, int quantile_size);
int				max_element(t_stack *a);
int				get_quantile_number(int nbr);
float			ft_sqrt(int nb);
int				next_val(t_stack *s, int val);
int				min_element(t_stack *a);

void			swap(t_stack **stack);
void			push(t_stack **a, t_stack **b);
void			reverse_rotate(t_stack **s);
void			rotate(t_stack **s);
int				print_stack(t_stack *a, t_stack *b);
int				check(t_stack *s, t_stack *b);

#endif
