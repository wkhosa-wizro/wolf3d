/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:47:15 by wkhosa            #+#    #+#             */
/*   Updated: 2018/05/06 12:48:39 by wkhosa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_MANAGER_H
# define IMAGE_MANAGER_H

# define BITS_PER_PIXEL 32

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef	struct	s_mlxdata
{
	void		*ptr;
	int			width;
	int			height;
	char		*title;
	int			bppixel;
	int			sline;
	int			endian;
	void		*img;
	void		*win;
	char		*img_addr;
}				t_mlxdata;

t_mlxdata		*init_image(int width, int height, char *title);
char			*get_img_addr(t_mlxdata *mlx);
void			update_image(t_mlxdata *mlx);
#endif
