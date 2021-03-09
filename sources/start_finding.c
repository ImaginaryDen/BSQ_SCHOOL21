/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_finding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:55:48 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/09 20:56:15 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	set_obstacle(t_obstacle *list, int *line)
{
	if (!list)
		return ;
	line[list->x] = 0;
	set_obstacle(list->next, line);
	free(list);
}

int		first_line(t_map *map, int **line_1, int **line_2)
{
	char		buffer;
	t_obstacle	*list;
	int			i;

	read(map->file, &buffer, 1);
	list = NULL;
	while (buffer != '\n')
	{
		if (buffer == map->valid[OBSTACLE])
			add_v(&list, map->colum, 0);
		else if (buffer != map->valid[EMPTY])
			return (0);
		if (!read(map->file, &buffer, 1))
			break ;
		map->colum++;
	}
	*line_1 = (int *)malloc(sizeof(int) * map->colum);
	*line_2 = (int *)malloc(sizeof(int) * map->colum);
	if (!*line_1 || !*line_2)
		return (0);
	i = 0;
	while (i < map->colum)
		(*line_1)[i++] = 1;
	set_obstacle(list, (*line_1));
	return (1);
}

int		start_finding(t_map *map, t_sqr *sqr)
{
	char	buffer;
	int		f;
	int		i;
	t_lines lines;

	f = 1;
	if (!check_map(map, map->file))
		return (0);
	f = first_line(map, &lines.line1, &lines.line2);
	lines.buffer = (char *)malloc(map->colum);
	i = -1;
	while (++i < map->colum && !sqr->size)
		if (lines.line1[i])
		{
			sqr->size = 1;
			sqr->x = i;
		}
	if (f && !find_sqr(&lines, map, sqr, 1))
		f = 0;
	if (f && read(map->file, &buffer, 1))
		f = 0;
	free(lines.line1);
	free(lines.line2);
	free(lines.buffer);
	return (f);
}
