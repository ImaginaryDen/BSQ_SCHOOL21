/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:38:57 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/08 17:08:26 by tjamis           ###   ########.fr       */
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

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

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
t_sqr					find_sqr(t_obstacle **list, t_map map);

#endif
