/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:56:02 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/10 21:53:19 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_pt(float x, float y, t_pt *pt, t_data *data)
{
	pt->z = data->matrix[(int)y][(int)x];
	pt->x = x;
	pt->y = y;
	pt->color = get_default_color(pt->z, data);
	pt->z -= ((pt->z / 10) * data->z_scale) / 5;
	ft_project(pt, data);
}

void	make_grid(t_pt *from, t_pt *to, t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				make_pt(x, y, from, data);
				make_pt(x + 1, y, to, data);
				draw_line(from, to, data);
			}
			if (y < data->height - 1)
			{
				make_pt(x, y, from, data);
				make_pt(x, y + 1, to, data);
				draw_line(from, to, data);
			}
			x++;
		}
		y++;
	}
}

void	make_grid_rev(t_pt *from, t_pt *to, t_data *data)
{
	int		y;
	int		x;

	y = data->height - 1;
	while (y >= 0)
	{
		x = data->width - 1;
		while (x >= 0)
		{
			if (x > 0)
			{
				make_pt(x, y, from, data);
				make_pt(x - 1, y, to, data);
				draw_line(from, to, data);
			}
			if (y > 0)
			{
				make_pt(x, y, from, data);
				make_pt(x, y - 1, to, data);
				draw_line(from, to, data);
			}
			x--;
		}
		y--;
	}
}

int	get_inversion(t_data *data)
{
	int	invert;

	invert = 1;
	if (data->ang_z > PI / 2 && data->ang_z < 3 * PI / 2)
			invert *= -1;
	if (data->ang_x > 0 && data->ang_x < PI)
			invert *= -1;
	return (invert);
}
