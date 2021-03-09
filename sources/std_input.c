/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mslyther <mslyther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:24:46 by mslyther          #+#    #+#             */
/*   Updated: 2021/03/09 20:56:18 by mslyther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	std_input(void)
{
	int		file;
	char	buffer[10000];
	int		size;

	file = open("std_input", O_WRONLY | O_TRUNC);
	while ((size = read(0, buffer, 10000)) != 0)
		write(file, buffer, size);
	close(file);
}
