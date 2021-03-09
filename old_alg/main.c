/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:51:18 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/08 17:07:49 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdio.h>
void print_list(t_obstacle *list);

void print_arr(t_sqr result, char *name, t_map map)
{
	int i;
	int j;
	int file;
	char bufer;

	if ((file = open(name, O_RDWR)) == -1)
		return ;
	read(file,&bufer,1);
	while (bufer != '\n')
		read(file,&bufer,1);
	i = 0;
	j = 0;
	while (read(file,&bufer,1))
	{
		if (bufer == '\n')
		{
			i = -1;
			j++;
		}
		if (i >= result.x && i < result.x + result.size &&
			j >= result.y && j < result.y + result.size)
			write(1, &map.valid[2], 1);
		else
			write(1, &bufer, 1);
		//printf("x - %d y - %d\n", i, j);
		i++;
	}
	close(file);
}

int main(int argc, char **argv)
{
	t_map		map;
	t_obstacle	*list;
	int			i;
	int			size;
	t_sqr		result;

	list = NULL;
	i = 1;
	while(i < argc)
	{
		if((size = fill_obstacle(&list, &map, argv[i])) == -1)
		{
			error_msg("Error\n");
			return (0);
		}
		printf("m.c - %d\nm.l - %d\nm.v[0] - %c\nm.v[1] - %c\nm.v[2] - %c\n",map.colum, map.line, map.valid[0], map.valid[1], map.valid[2]);
		//print_list(list);
		//read(1,&size,1);
		result = find_sqr(&list, map);
		ft_list_clear(list);
		print_arr(result, argv[i], map);
		i++;
		
	}


}