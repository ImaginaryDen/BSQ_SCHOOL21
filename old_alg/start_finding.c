/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 19:06:52 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/08 17:09:53 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdio.h>

void del_l(t_obstacle **list)
{
	t_obstacle *del;

	del = *list;
	(*list) = (*list)->next;
	free(del);	
}

int find_sqr_pos(t_point pos, t_obstacle **list, t_map map, int max_sqr)
{
	int max;
	int x_count;
	int y_count;
	int result;

	if(!*list)
	{
		x_count= map.colum - pos.x;
		y_count = map.line - pos.y;
		//printf("point: i -- %d j -- %d\n", x_count, y_count);
		return (x_count < y_count ? x_count : y_count);
	}
	x_count = (*list)->x - pos.x;
	y_count = (*list)->y - pos.y;
	if(x_count < 0 || y_count < 0)
		max = map.colum;
	else
		max = y_count > x_count ? y_count : x_count;
	if(!max_sqr && max < max_sqr)
		return (0);
	if(y_count < 0)
	{
		del_l(list);
		result = find_sqr_pos(pos, list, map, max);
		return  (result < max ? result : max); 
	}
	//printf("%d x -- %d y -- %d\n x_l - %d y_l - %d\n", max, x, y, list->x, list->y);
	//read(1, &result, 1);
	result = find_sqr_pos(pos, &(*list)->next, map, max);
	return  (result < max ? result : max); 
}

t_sqr find_sqr(t_obstacle **list, t_map map)
{
	t_sqr	result;
	t_point pos;
	int		count;

	pos.y = 0;
	result.size = 0;
	while (pos.y < map.line - result.size)
	{
		pos.x = 0;
		while(pos.x < map.colum - result.size)
		{
			if((count = find_sqr_pos(pos, list, map, result.size)) > result.size && count + pos.x <= map.colum && count + pos.y <= map.line)
			{
				result.x = pos.x;
				result.y = pos.y;
				result.size = count;
				//printf("size %d x - %d y - %d\n", count, x, y);
			}
			//printf("count - %d x - %d y - %d\n\n", count, x, y);
			pos.x++;
		}
		pos.y++;
	}
	return (result);
}