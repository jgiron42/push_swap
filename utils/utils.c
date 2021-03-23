/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:44:27 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 16:48:44 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_strlen(char *str)
{
	char *tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp)
		tmp++;
	return ((int)((intptr_t)tmp - (intptr_t)str));
}

char *ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int 	i;

	i = -1;
	if (!(ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		exit (1);
	while (s1 && s1[++i])
		ret[i] = s1[i];
	i = -1;
	while (s2 && s2[++i])
		ret[ft_strlen(s1) + i] = s2[i];
	ret[ft_strlen(s2) + i] = 0;
	return (ret);
}

char	*ft_strjoinf1(char *s1, char *s2)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	return (ret);
}

int		cmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i])
		;
	return (s1[i] == s2[i]);
}

int	print_stack(t_stack *a, t_stack *b)
{
	int ret;

	ret = printf("_______   _______\n");
//	ret = printf("\e[1;1H\e[2J_______   _______\n");
	while (a || b)
	{
		if (a && b)
			ret += printf("| %3d |   | %3d |\n", a->value, b->value);
		if (!a && b)
			ret += printf("|     |   | %3d |\n", b->value);
		if (a && !b)
			ret += printf("| %3d |   |     |\n", a->value);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ret += printf("|_____|   |_____|\n");
	return (ret);
}