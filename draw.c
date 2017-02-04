/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 21:51:33 by jcentaur          #+#    #+#             */
/*   Updated: 2017/02/04 06:09:28 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_to_image(t_info *info, t_point pos, int color)
{
	int i;

	if (pos.x > info->sizeimg.x || pos.y > info->sizeimg.y
			|| pos.x < 0 || pos.y < 0)
		return ;
	if (info->endian == 0)
	{
		i = (info->sizeline * pos.y) + (pos.x * (info->bpp / 8));
		info->data[i] = mlx_get_color_value(info->img, color);
		info->data[i + 1] = mlx_get_color_value(info->img, color >> 8);
		info->data[i + 2] = mlx_get_color_value(info->img, color >> 16);
	}
	else
	{
		i = (info->sizeline * pos.y) + (pos.x * (info->bpp / 8));
		info->data[i] = mlx_get_color_value(info->img, color >> 16);
		info->data[i + 1] = mlx_get_color_value(info->img, color >> 8);
		info->data[i + 2] = mlx_get_color_value(info->img, color);
	}
}

void	ft_scale(t_info *i, t_point *a, t_point *b)
{
	int		scale;

	scale = 2;
	if (i->size.x * i->size.y < 750)
		scale *= 10;
	a->x *= scale;
	a->y *= scale;
	b->x *= scale;
	b->y *= scale;
	a->z *= -5;
	b->z *= -5;
}

void	ft_draw_iso(t_info *i, t_point a, t_point b, double cst[2])
{
	int		color;

	color = 0xFF0000;
	if (a.z + b.z >= 10)
		color = 0xFFA500;
	if (a.z + b.z >= 20)
		color = 0xFFFF00;
	if (a.z + b.z >= 30)
		color = 0xFFFFFF;
	if (a.z + b.z >= 42)
		color = 0x0000FF;
	ft_scale(i, &a, &b);
	a.x += 300 + cst[0] * a.x - cst[1] * a.y;
	a.y += 300 + a.z + (cst[0] / 2) * a.x + (cst[0] / 2) * a.y;
	b.x += 300 + cst[0] * b.x - cst[1] * b.y;
	b.y += 300 + b.z + (cst[0] / 2) * b.x + (cst[0] / 2) * b.y;
	ligne(i, a, b, color);
}
