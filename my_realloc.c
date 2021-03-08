/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 00:50:22 by tjamis            #+#    #+#             */
/*   Updated: 2021/03/07 15:10:57 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	*my_realloc(void *old, int size)
{
	void	*new;
	int		i;

	new = malloc(size);
	i = 0;
	while (i < size && old)
	{
		((char*)new)[i] = ((char*)old)[i];
		i++;
	}
	free(old);
	return (new);
}
