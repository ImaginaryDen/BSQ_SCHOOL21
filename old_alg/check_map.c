/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:16:24 by mslyther          #+#    #+#             */
/*   Updated: 2021/03/08 15:32:13 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		printable(char ch)
{
	if (ch >= 0 && ch <= 126)
		return (1);
	return (0);
}

int		put_first_str(char **str, int fd)
{
	char ch;
	int i;

	i = 0;
	*str = NULL;
	while (read(fd, &ch, 1) && ch != '\n' && printable(ch))
	{
		*str = my_realloc(*str, i + 2);
		(*str)[i] = ch;
		i++;
	}
	(*str)[i] = '\0';
	if (!printable(ch))
		i = 0;
	return (i);
}

int		my_atoi(char *str, int size)
{
	int num;
	int i;

	num = 0;
	i = 0;
	if (!*str || *str == '-' || *str == '0')
		return (0);
	while (i < size - 3)
	{
		if (str[i] <= '0' && str[i] >= '9')
			return (0);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}	

int		check_valid_ch(char *valid)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE_VALID)
	{
		j = i + 1;
		while (j < SIZE_VALID)
		{
			if (valid[i] == valid[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_map(t_map *map, int fd)
{
	int i;
	int size_first;
	char *str;

	size_first = put_first_str(&str, fd);
	if (size_first < 4)
		return (0);
	i = 1;
	while (i <= SIZE_VALID)
	{
		map->valid[SIZE_VALID - i] = str[size_first - i];
		i++;
	}
	if (!check_valid_ch(map->valid))
		return (0);
	map->line = my_atoi(str, size_first);
	if (!(map->line))
		return (0);
	return (1);
}
