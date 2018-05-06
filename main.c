/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:38:14 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 12:44:04 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"
#include "libft/libft.h"
#include <math.h>

char	**read_map(const char *file)
{
	int			fd;
	char		buf[(MAP_L + 1) * (MAP_W + 1) + 1];
	char		**map;
	int			byt;
	size_t		bytes;

	bytes = sizeof(buf);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("Failed to open map ...");
		exit(1);
	}
	if ((byt = read(fd, buf, bytes)) < 0)
	{
		ft_putendl("failed to read from map\n");
		exit(1);
	}
	map = ft_strsplit(buf, '\n');
	return (map);
}

t_w3d	*init_wolf3d(char *file)
{
	t_w3d		*w3d;
	t_mlxdata	*mlx;
	t_2dpoint	pt0;

	pt0.y = (START_W - 0.5) * GRID_S;
	pt0.x = (START_L - 0.5) * GRID_S;
	w3d = (t_w3d *)malloc(sizeof(t_w3d));
	mlx = init_image(PLANE_W, PLANE_H, "Wolf3d </wethinkcode>");
	w3d->mlx = mlx;
	w3d->cam = pt0;
	w3d->map = read_map(file);
	w3d->dir = 3 * M_PI / 2;
	return (w3d);
}

int		main(int ac, char **av)
{
	t_w3d		*w3d;
	t_mlxdata	*mlx;

	if (ac != 2)
	{
		ft_putendl("wrong number of arguments");
		return (0);
	}
	else
	{
		w3d = init_wolf3d(av[1]);
		mlx = w3d->mlx;
		mlx_key_hook(mlx->win, key_hook, (void *)w3d);
		mlx_hook(mlx->win, 17, 0, exit_hook, (void *)w3d);
		mlx_loop(mlx->ptr);
	}
	return (0);
}
