/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/10/08 21:50:08 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_pt *from, t_pt *to, t_pt *current, t_data *data)
{
	int	i;
	int	color;

	if (current->x > 0 && current->x < data->size_line / 4 && current->y > 0
		&& current->y < data->winheight)
	{
		i = (((int)(current->x) * (data->bits_per_pixel / 8))
				+ ((int)(current->y) * (int)(data->size_line)));
		color = get_color(from, to, current);
		data->addr[i] = color;
		data->addr[i + 1] = color >> 8;
		data->addr[i + 2] = color >> 16;
	}
}

void	draw_line(t_pt *from, t_pt *to, t_data *data)
{
	float	xstep;
	float	ystep;
	t_pt	*current;
	int		max;

	current = malloc(sizeof (t_pt));
	current->x = from->x;
	current->y = from->y;
	xstep = to->x - from->x;
	ystep = to->y - from->y;
	max = get_max(xstep, ystep);
	xstep /= max;
	ystep /= max;
	while ((int)(current->x - to->x) || (int)(current->y - to->y))
	{
		ft_put_pixel(from, to, current, data);
		current->x += xstep;
		current->y += ystep;
	}
	free(current);
}

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
				draw_line_v2(from, to, data);
			}
			if (y < data->height - 1)
			{
				make_pt(x, y, from, data);
				make_pt(x, y + 1, to, data);
				draw_line_v2(from, to, data);
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
				draw_line_v2(from, to, data);
			}
			if (y > 0)
			{
				make_pt(x, y, from, data);
				make_pt(x, y - 1, to, data);
				draw_line_v2(from, to, data);
			}
			x--;
		}
		y--;
	}
}

int		get_inversion(t_data *data)
{
		int	invert;

		invert = 1;
		if (data->ang_z > 1/2 * PI && data->ang_z < 3/2 * PI)
				invert = -1;
		if (data->ang_y > 1/2 * PI && data->ang_y < 3/2 * PI)
				invert = -1;
		if (data->ang_x > 1/2 * PI && data->ang_x < 3/2 * PI)
				invert = -1;
		return (invert);
}

void	draw(t_data *data)
{
	t_pt	*from;
	t_pt	*to;
	int		invert;

	from = malloc(sizeof (t_pt));
	to = malloc(sizeof (t_pt));
	mlx_destroy_image(data->mlx, data->img);
	//write(1, "before\n", 7);
	data->img = mlx_new_image(data->mlx, data->winwidth, data->winheight);
	//write(1, "after\n", 6);
	data->addr = mlx_get_data_addr(data->img,
			&(data->bits_per_pixel), &(data->size_line), &(data->endian));
	invert = get_inversion(data);
	if (invert == -1)
		make_grid_rev(from, to, data);
	else
		make_grid(from, to, data);
	free(from);
	free(to);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
