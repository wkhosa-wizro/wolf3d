/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:49:20 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 13:27:42 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "geometry.h"
# include "image_manager.h"

# define PLANE_W 800
# define PLANE_H 600

# define FOV (M_PI / 3)
# define CAM_TO_PLANE ((PLANE_W / 2) / tan(FOV / 2))

# define WALL_H 10
# define WALL_W 10
# define WALL_L 10

# define MAP_L 10
# define MAP_W 10

# define START_L 3
# define START_W 2
# define STEP 1
# define GRID_S 10
# define ANG_I   (FOV / (double)PLANE_W)

# define LEFT    123
# define RIGHT   124
# define UP      126
# define DOWN    125
# define ESC     53

# define BLUE    0x004286F4
# define RED     0x00AF011B
# define GREEN   0x0022AD1D
# define YELLOW  0x00FFF321

typedef	struct	s_w3d
{
	t_mlxdata	*mlx;
	t_2dpoint	cam;
	double		dir;
	char		**map;
	int			map_w;
	int			map_l;
}				t_w3d;

int				key_hook(int keycode, void *w3d);
char			get_map_elem(t_2dpoint pt, char	**map);
int				get_color(double dir, t_2dpoint pt, char **map);
double			find_dist_to_wall(double dir, t_2dpoint pt, char **map);
double			find_wall_height(double dir, double beta, t_2dpoint pt, \
				char **map);
void			draw_wall(double dir, t_2dpoint pt, t_mlxdata *mlx, char **map);
int				exit_hook(void);

#endif
