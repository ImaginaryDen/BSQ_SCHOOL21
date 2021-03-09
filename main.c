/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:51:18 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/09 21:54:10 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/bsq.h"

void	print_arr(t_sqr result, char *name, t_map map)
{
	int		i;
	int		file;
	char	buffer[map.colum + 1];
	char	buffer_obst[result.size + 1];

	if ((file = open(name, O_RDWR)) == -1)
		return ;
	read(file, &buffer, 1);
	while (*buffer != '\n')
		read(file, &buffer, 1);
	i = 0;
	while (i < result.size)
		buffer_obst[i++] = map.valid[FULL];
	i = -1;
	while (read(file, buffer, map.colum + 1))
		if (++i > result.y - result.size && i <= result.y)
		{
			write(1, buffer, result.x - result.size + 1);
			write(1, buffer_obst, result.size);
			write(1, buffer + result.x + 1, map.colum - result.x);
		}
		else
			write(1, buffer, map.colum + 1);
	close(file);
}

void	ziroing(t_map *map, t_sqr *res)
{
	map->colum = 0;
	map->file = 0;
	map->line = 0;
	map->valid[0] = 0;
	map->valid[1] = 0;
	map->valid[2] = 0;
	res->size = 0;
	res->x = 0;
	res->y = 0;
}

int		solve_sqr(char *name, t_map map, t_sqr result)
{
	if ((map.file = open(name, O_RDWR)) == -1 ||
		!start_finding(&map, &result))
	{
		error_msg("map error\n");
		close(map.file);
		return (0);
	}
	close(map.file);
	print_arr(result, name, map);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map		map;
	int			i;
	t_sqr		result;

	i = 1;
	while (i < argc)
	{
		if (i != 1)
			write(1, "\n", 1);
		ziroing(&map, &result);
		solve_sqr(argv[i], map, result);
		i++;
	}
	if (argc == 1)
	{
		std_input();
		ziroing(&map, &result);
		solve_sqr("std_input", map, result);
		close(open("std_input", O_WRONLY | O_TRUNC));
	}
}
