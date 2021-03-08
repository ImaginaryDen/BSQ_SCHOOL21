/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:38:57 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/08 22:55:59 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdlib.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct			s_map
{
	int					line;
	int					colum;
	char				valid[3];
	int					file;
}						t_map;

typedef struct			s_obstacle
{
	int					x;
	int					y;
	struct s_obstacle	*next;
}						t_obstacle;

typedef struct			s_sqr
{
	int					x;
	int					y;
	int					size;
}						t_sqr;

typedef struct			s_lines
{
	int					*line1;
	int					*line2;
	char				*buffer;
}						t_lines;

enum					e_ch
{
	EMPTY,
	OBSTACLE,
	FULL
};

# define SIZE_VALID 3
# define END_ARR -1

int						check_map(t_map *, int file);
int						fill_arr(t_map, int ***, char *);
void					error_msg(char *str);
void					*my_realloc(void *old, int size);
int						fill_obstacle(t_obstacle **arr, t_map *map, char *name);
int						check_valid_ch(char *valid);
void					ft_list_clear(t_obstacle *begin_list);
void					add_v(t_obstacle **arr, int i, int j);
int						start_finding(t_map *map, t_sqr *sqr);
int						find_sqr(t_lines *lines, t_map *map, t_sqr *sqr, int y);

#endif
