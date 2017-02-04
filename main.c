/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:56:26 by jcentaur          #+#    #+#             */
/*   Updated: 2017/02/04 02:39:04 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		nb_ligne(char *s)
{
	int		fd;
	int		res;
	char	*buf;

	res = 0;
	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &buf))
		res++;
	return (res);
}

int		main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_info		info;
	int			**map;

	if (ac != 2)
		return (0);
	mlx = mlx_init();
	info.sizeimg.x = 1000;
	info.sizeimg.y = 1000;
	info.size.y = nb_ligne(av[1]);
	map = getmap(av[1], info.size.y, &info.size.x);
	printf("size : [%d,%d]\n", info.size.x, info.size.y);
	info.img = mlx_new_image(mlx, info.sizeimg.x, info.sizeimg.y);
	info.data = mlx_get_data_addr(info.img, &info.bpp, &info.sizeline, &info.endian);
	printf("size : [%d,%d]\n", info.size.x, info.size.y);
	ft_drawmap(&info, map);
	printf("size : [%d,%d]\n", info.size.x, info.size.y);
	win = mlx_new_window(mlx, info.sizeimg.x, info.sizeimg.y, "CENTAURE");
	mlx_put_image_to_window(mlx, win, info.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
