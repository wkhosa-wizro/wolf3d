/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:44:36 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 12:47:07 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <math.h>
# include "image_manager.h"

typedef	struct	s_2dpoint
{
	double		x;
	double		y;
}				t_2dpoint;

void			vert_line(t_2dpoint p0, t_2dpoint p1, t_mlxdata *mlx,\
		int color);
#endif
