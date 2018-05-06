/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:35:50 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 12:37:38 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/image_manager.h"

t_mlxdata	*init_image(int width, int height, char *title)
{
	t_mlxdata	*mlx;

	mlx = (t_mlxdata *)malloc(sizeof(t_mlxdata));
	mlx->ptr = mlx_init();
	mlx->width = width;
	mlx->height = height;
	mlx->title = title;
	mlx->bppixel = BITS_PER_PIXEL;
	mlx->sline = BITS_PER_PIXEL * mlx->width;
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, mlx->title);
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &(mlx->bppixel), \
	&(mlx->sline), &(mlx->endian));
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (mlx);
}

void		update_image(t_mlxdata *mlx)
{
	int			i;
	int			*temp;

	i = 0;
	temp = (int *)mlx->img_addr;
	while (i < (mlx->height * mlx->width))
		temp[i++] = 0x00111111;
}
