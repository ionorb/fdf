/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:08:29 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/24 15:38:24 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*cpy_struc(t_data *data)
{
	t_data	*cpy;

	cpy = malloc(sizeof (t_data));
	cpy->x_offset = data->x_offset;
	cpy->y_offset = data->y_offset;
	cpy->ang_x = data->ang_x;
	cpy->ang_y = data->ang_y;
	cpy->ang_z = data->ang_z;
	cpy->zoom = data->zoom;
	cpy->z_scale = data->z_scale;
	return (cpy);
}

float	angle_range(float end, float start)
{
		printf("end:%f, stsart:%f, diff:%f\n", end, start, ft_abs(start - end));
		while (start > 6.283)
				start -= 6.283;
		while (start < -6.283)
				start += 6.283;
		printf("end:%f, stsart:%f, diff:%f\n", end, start, ft_abs(start - end));
		return ((end - start) / 100);
}

void	make_isometric(t_data *data)
{
	int		i;
	t_data	*cpy;

	cpy = cpy_struc(data);
	i = 0;
	while (i < 100)
	{
		data->x_offset += ((data->winwidth / 2) / 42 - cpy->x_offset
				- data->width / 2 + 1) / 100;
		data->y_offset += ((data->winheight / 2) / 42 - cpy->y_offset
				- data->height / 2) / 100;
		data->ang_x += angle_range(-0.5, cpy->ang_x);//(-0.5 - cpy->ang_x) / 100;
		data->ang_y += angle_range(0, cpy->ang_y);//(0 - cpy->ang_y) / 100;
		printf("ang_y:%f, diff:%f\n", data->ang_y, angle_range(0, cpy->ang_x));
		data->ang_z += angle_range(0.8, cpy->ang_z);//(0.8 - cpy->ang_z) / 100;
		data->zoom += (42 - cpy->zoom) / 100;
		data->z_scale += (42 - cpy->z_scale) / 100;
//		data->img = mlx_new_image(data->mlx, data->winwidth, data->winheight);
//		data->addr = mlx_get_data_addr(data->img,
//				&(data->bits_per_pixel), &(data->size_line), &(data->endian));
		draw(data);
		i++;
	}
	free(cpy);
}

void	ft_project(t_pt *pt, t_data *data)
{
	t_pt	*save;
	t_pt	*origin;

	origin = malloc(sizeof (t_pt));
	save = malloc(sizeof (t_pt));
	origin->x = data->width / 2 + data->x_offset;
	origin->y = data->height / 2 + data->y_offset;
	origin->z = 0;
	pt->x += data->x_offset;
	pt->y += data->y_offset;
	save->x = pt->x - origin->x;
	save->y = pt->y - origin->y;
	save->z = pt->z;
	rotate_z(pt, save, data);
	rotate_y(pt, save, data);
	rotate_x(pt, save, data);
	pt->x += origin->x;
	pt->y += origin->y;
	pt->x *= data->zoom;
	pt->y *= data->zoom;
}
