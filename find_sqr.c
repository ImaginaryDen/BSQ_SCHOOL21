/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:12:42 by mslyther          #+#    #+#             */
/*   Updated: 2021/03/08 23:46:30 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdio.h>

int		find_min(t_lines *lines, int i)
{
	int min;

	if (i == 0)
		return (0);
	min = lines->line1[i - 1] < lines->line1[i] ? lines->line1[i - 1] : lines->line1[i];
	min = min < lines->line2[i - 1] ? min : lines->line2[i - 1];
	return (min);
}

void	swap(t_lines *lines)
{
	int *temp;

	temp = lines->line1;
	lines->line1 = lines->line2;
	lines->line2 = temp;
}

int		find_sqr(t_lines *lines, t_map *map, t_sqr *sqr, int y)
{
	char check;
	int i;

	//printf("@\n");
	if (y == map->line)
		return (1);
	read(map->file, lines->buffer, map->line);
	read(map->file, &check, 1);
	if (check != '\n')
		return (0);
	i = 0;
	while (i < map->colum)
	{
		if (lines->buffer[i] == map->valid[OBSTACLE])
		{
			lines->line2[i] = 0;
			i++;
			//printf("0");
			continue;
		}
		if (lines->buffer[i] == map->valid[EMPTY])
		{
			lines->line2[i] = 1 + find_min(lines, i);
			//printf("%d", lines->line2[i]);
			if (lines->line2[i] > sqr->size)
			{
				sqr->size = lines->line2[i];
				sqr->x = i;
				sqr->y = y;
			}
			i++;
			continue;
		}
		return (0);
	}
	//puts("");
	swap(lines);
	return find_sqr(lines, map, sqr, y + 1);
}
