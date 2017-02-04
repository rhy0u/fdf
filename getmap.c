/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:06:40 by jcentaur          #+#    #+#             */
/*   Updated: 2017/02/04 02:35:23 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**getmap(char *path, int y, int *x)
{
	char	*buf;
	int		**tab;
	int		i;
	int		fd;

	if (!(tab = (int **)malloc(sizeof(int *) * y)))
		return (0);
	i = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &buf))
	{
		tab[i++] = intsplit(buf, x);
		free(buf);
	}
	return (tab);
}
