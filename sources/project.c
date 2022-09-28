/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:08:29 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/29 01:11:18 by yridgway         ###   ########.fr       */
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
	while (start > 6.283)
		start -= 6.283;
	while (start < -6.283)
		start += 6.283;
	if (ft_abs(end - start + 6.283) < ft_abs(end - start)
		|| ft_abs(end - start - 6.283) < ft_abs(end - start))
	{
		if (ft_abs(end - start + 6.283) < ft_abs(end - start - 6.283))
			return ((end - start + 6.283) / 100);
		else
			return ((end - start - 6.283) / 100);
	}
	return ((end - start) / 100);
}

int	ft_struc_cmp(t_data *data, t_data *cpy)
{
	float	diff;

	diff = 0;
	diff += ft_abs(cpy->x_offset - ((data->winwidth / 2) / 42
				- data->width / 2 + 1));
	diff += ft_abs(cpy->y_offset - ((data->winheight / 2) / 42
				- data->height / 2));
	diff += ft_abs(cpy->ang_x - (-0.9)) * 5;
	diff += ft_abs(cpy->ang_y - 0) * 5;
	diff += ft_abs(cpy->ang_z - 0.8) * 5;
	diff += ft_abs(cpy->zoom - 42) * 5;
	diff += ft_abs(cpy->z_scale - 42) * 5;
	return ((int)ft_abs(diff));
}

void	make_isometric(t_data *data)
{
	int		i;
	t_data	*cpy;

	cpy = cpy_struc(data);
	i = 0;
	while (ft_struc_cmp(data, cpy) && i < 100)
	{
		data->x_offset += ((data->winwidth / 2) / (data->winwidth
					/ (data->width * 1.5)) - (data->width / 2)
				- cpy->x_offset) / 100;
		data->y_offset += ((data->winheight / 2) / (data->winwidth
					/ (data->width * 1.5)) - (data->height / 2)
				- cpy->y_offset) / 100;
		data->ang_x += angle_range(-0.9, cpy->ang_x);
		data->ang_y += angle_range(0, cpy->ang_y);
		data->ang_z += angle_range(0.8, cpy->ang_z);
		data->zoom += (data->winwidth / (data->width * 1.5) - cpy->zoom) / 100;
		data->z_scale += (42 - cpy->z_scale) / 100;
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
	pt->x = pt->x * data->zoom + data->mousex; 
	pt->y = pt->y * data->zoom + data->mousey;
	free(origin);
	free(save);
}
