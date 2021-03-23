/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiron <jgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:43:56 by jgiron            #+#    #+#             */
/*   Updated: 2021/03/23 12:38:16 by jgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//int		get_next_line(int fd, char **line)
//{
//	char	*buff;
//	int		size;
//
//	*line = NULL;
//	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
//		exit(1);
//	while ((!*line || (*line)[ft_strlen(*line) - 1] != '\n'))
//	{
//		size = read(fd, buff, BUFFER_SIZE);
//		if (!size)
//		{
//			break ;
//		}
//		buff[size * (size >= 0)] = 0;
//		if (!(*line = ft_strjoinf1(*line, buff)))
//			exit(1);
//	}
//	free(buff);
//	return (!!size);
//}