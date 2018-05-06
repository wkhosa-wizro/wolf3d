/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:27:35 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 13:10:37 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"

void	rotate_cam(t_w3d *w, int keycode)
{
	if (keycode == LEFT)
		w->dir = (w->dir + (M_PI / 12));
	if (keycode == RIGHT)
		w->dir = (w->dir - (M_PI / 12));
}

void	move_cam(t_w3d *w, int keycode)
{
	t_2dpoint	pt;
	char		elem;

	pt = w->cam;
	if (keycode == UP)
	{
		w->cam.x = w->cam.x + STEP * cos(w->dir);
		w->cam.y = w->cam.y + STEP * sin(w->dir);
		elem = get_map_elem(w->cam, w->map);
		if (elem > 'A' && elem != '0')
		{
			w->cam = pt;
		}
	}
	if (keycode == DOWN)
	{
		w->cam.x = w->cam.x - STEP * cos(w->dir);
		w->cam.y = w->cam.y - STEP * sin(w->dir);
		elem = get_map_elem(w->cam, w->map);
		if (elem > 'A' && elem != '0')
			w->cam = pt;
	}
}

int		key_hook(int keycode, void *w3d)
{
	t_w3d		*w;
	t_mlxdata	*mlx;

	w = (t_w3d *)w3d;
	mlx = w->mlx;
	if (keycode == LEFT || keycode == RIGHT)
		rotate_cam(w, keycode);
	if (keycode == UP || keycode == DOWN)
		move_cam(w, keycode);
	if (keycode == ESC)
		exit(1);
	update_image(mlx);
	draw_wall(w->dir, w->cam, w->mlx, w->map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		exit_hook(void)
{
	exit(3);
}
