/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:14:00 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 12:17:45 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/geometry.h"
#include "include/image_manager.h"

void	vert_line(t_2dpoint p0, t_2dpoint p1, t_mlxdata *mlx, int color)
{
	int			*temp;
	int			index;
	t_2dpoint	point;

	temp = (int *)mlx->img_addr;
	if (p0.y > p1.y)
	{
		point = p1;
		p1 = p0;
		p0 = point;
	}
	while (p0.y < p1.y)
	{
		index = ((int)p0.x % mlx->width) + ((int)p0.y) * (mlx->width);
		p0.y += 1;
		temp[index++] = color;
	}
}
