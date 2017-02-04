/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:35:23 by jcentaur          #+#    #+#             */
/*   Updated: 2017/02/04 05:59:07 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawmap(t_info *i, int **map)
{
	t_point right;
	t_point down;
	t_point	pos;
	double cst[2];

	cst[0] = 1;
	cst[1] = .7;
	pos.y = 0;
	while (pos.y < i->size.y)
	{
		pos.x = 0;
		while (pos.x < i->size.x)
		{
			pos.z = map[pos.y][pos.x];
			if (pos.x + 1 < i->size.x)
			{
				right.x = pos.x + 1;
				right.y = pos.y;
				right.z = map[pos.y][pos.x + 1];
				ft_draw_iso(i, pos, right, cst);
			}
			if (pos.y + 1 < i->size.y)
			{
				down.x = pos.x;
				down.y = pos.y + 1;
				down.z = map[pos.y + 1][pos.x];
				ft_draw_iso(i, pos, down, cst);
			}
			pos.x++;
		}
		pos.y++;
	}
}
