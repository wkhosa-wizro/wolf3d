/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:18:01 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 12:26:55 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"

char	get_map_elem(t_2dpoint pt, char **map)
{
	int			col;
	int			row;

	col = floor(((int)(pt.x)) / GRID_S);
	row = floor(((int)(pt.y)) / GRID_S);
	if ((col > MAP_L) || (col < 0) || (row > MAP_W) || (row < 0))
		return ('\0');
	return (map[row][col]);
}

int		get_color(double dir, t_2dpoint pt, char **map)
{
	double		dis;

	dis = 0;
	while (1)
	{
		if (get_map_elem(pt, map) > 'A')
		{
			if (get_map_elem(pt, map) == 'B')
				return (BLUE);
			if (get_map_elem(pt, map) == 'Y')
				return (YELLOW);
			if (get_map_elem(pt, map) == 'G')
				return (GREEN);
			if (get_map_elem(pt, map) == 'R')
				return (RED);
			if (get_map_elem(pt, map) == '\0')
				return (0);
		}
		dis = dis + 0.1;
		pt.x = (pt.x) + 0.1 * cos(dir);
		pt.y = (pt.y) + 0.1 * sin(dir);
	}
}

double	find_wall_height(double dir, double beta, t_2dpoint pt, char **map)
{
	double		dis;
	double		height;
	int			not_wall;

	dis = 0;
	not_wall = 1;
	while (not_wall)
	{
		if (get_map_elem(pt, map) > 'A')
		{
			not_wall = 0;
			break ;
		}
		dis = dis + 0.1;
		pt.x = (pt.x) + 0.1 * cos(dir);
		pt.y = (pt.y) + 0.1 * sin(dir);
	}
	height = ((WALL_H / (dis * cos(beta)) * CAM_TO_PLANE));
	return (height);
}

void	detect_collision(t_2dpoint *pt0, t_2dpoint *pt1, int max_height)
{
	if (pt0->y < 0)
		pt0->y = 0;
	if (pt0->y >= max_height)
		pt0->y = max_height;
	if (pt1->y < 0)
		pt1->y = 0;
	if (pt1->y >= max_height)
		pt1->y = max_height;
}

void	draw_wall(double dir, t_2dpoint pt, t_mlxdata *mlx, char **map)
{
	t_2dpoint	pt0;
	t_2dpoint	pt1;
	int			color;
	int			i;
	double		height;

	i = 0;
	dir = dir + (FOV / 2);
	while (i < PLANE_W)
	{
		height = find_wall_height(dir, (FOV / 2.0 - (i * (ANG_I))), pt, map);
		color = get_color(dir, pt, map);
		pt0.x = i;
		pt0.y = (int)(PLANE_W / 2 - (height / 2));
		pt1.x = i;
		pt1.y = (int)(PLANE_H / 2 + (height / 2));
		detect_collision(&(pt0), &(pt1), mlx->height);
		vert_line(pt0, pt1, mlx, color);
		dir = dir - ANG_I;
		i++;
	}
}
