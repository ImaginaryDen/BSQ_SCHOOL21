/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_obstacle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:35:32 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/08 16:04:32 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdio.h>

int find(t_map map, char ch)
{
	int i;

	i = 0;
	while (i < SIZE_VALID)
	{
		if(ch == map.valid[i])
			return (i);
		i++;
	}
	return (-1);
}

int find_obstacle(t_map *map, int file, t_obstacle **list)
{
	int		i;
	int		j;
	char	bufer;
	int		f;
	
	i = 0;
	f = -1;
	while (i < map->line)
	{
		j = -1;
		while (++j < map->colum || (!map->colum && bufer != '\n'))
			if(read(file, &bufer, 1) && (bufer == map->valid[1]))
				add_v(list, j, i);
			else if((bufer == map->valid[2] || find(*map, bufer) == -1) && map->colum)
				return (-1);
			else if(bufer == map->valid[0])
				f = 1;
		if(!map->colum)
			map->colum = j - 1;
		else if(!read(file, &bufer, 1) && bufer != '\n')
			return (-1);
		i++;
	}
	return (f);
}

int fill_obstacle(t_obstacle **list, t_map *map, char *name)
{
	int		file;
	char	bufer;
	int 	f;

	if ((file = open(name, O_RDWR)) == -1)
		return (-1);
	check_map(map, file);
	map->colum = 0;
	f = find_obstacle(map, file, list);
	if(read(file, &bufer, 1))
		f = -1;
	close(file);
	return (f);
}