/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowaline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:35:33 by jcentaur          #+#    #+#             */
/*   Updated: 2017/02/04 03:57:38 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	boucleH(t_info *info, t_point pos, t_point dif, int color)
{
	int		i;
	int		cumul;
	t_point	inc;

	i = 0;
	cumul = dif.x / 2;
	inc.x = ( dif.x > 0 ) ? 1 : -1;
	inc.y = ( dif.y > 0 ) ? 1 : -1;
	dif.x *= ( dif.x > 0 ) ? 1 : -1;
	dif.y *= ( dif.y > 0 ) ? 1 : -1;
	while (++i <= dif.x)
	{
		pos.x += inc.x;
		cumul += dif.y;
		if ( cumul >= dif.x)
		{
			cumul -= dif.x;
			pos.y += inc.y;
		}
		ft_put_pixel_to_image(info, pos, color);
	}
}


void	boucleV(t_info *info, t_point pos, t_point dif, int color)
{
	int		i;
	int		cumul;
	t_point	inc;

	i = 0;
	cumul = dif.y / 2 ;
	inc.x = ( dif.x > 0 ) ? 1 : -1;
	inc.y = ( dif.y > 0 ) ? 1 : -1;
	dif.x *= ( dif.x > 0 ) ? 1 : -1;
	dif.y *= ( dif.y > 0 ) ? 1 : -1;
	while (++i <= dif.y)
	{
		pos.y += inc.y;
		cumul += dif.x;
		if (cumul >= dif.y)
		{
			cumul -= dif.y;
			pos.x += inc.x;
		}
		ft_put_pixel_to_image(info, pos, color);
	}
}

void	ligne(t_info *info, t_point a, t_point b, int color)
{
	t_point		pos;
	t_point		dif;

	pos.x = a.x;
	pos.y = a.y;
	dif.x = b.x - a.x;
	dif.y = b.y - a.y;
	ft_put_pixel_to_image(info, pos, color);
	if (abs(dif.x) > abs(dif.y))
		boucleH(info, pos, dif, color);
	else
		boucleV(info, pos, dif, color);
}
