/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:59:25 by jcentaur          #+#    #+#             */
/*   Updated: 2017/02/04 03:57:33 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct		s_line
{
	char			*str;
	struct s_line	*next;
}					t_line;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_info
{
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
	t_point			size;
	t_point			sizeimg;
}					t_info;

int					*intsplit(char const *s, int *nb);
int					**getmap(char *path, int y, int *x);
void				ft_draw_para(t_info *i, t_point a, t_point b, double cst);
void				ft_draw_iso(t_info *i, t_point a, t_point b, double cst[2]);
void				ft_drawmap(t_info *i, int **map);
void				ft_put_pixel_to_image(t_info *i, t_point, int);
void				ligne(t_info *i, t_point, t_point, int color);


#endif

