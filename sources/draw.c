/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/20 17:13:17 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	percentage(int start, int end, int current)
{
	float	current_loc;
	float	distance;

	current_loc = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	return (current_loc / distance);
}

int	get_color(t_pt *from, t_pt *to, t_pt *current)
{
	int	r;
	int	g;
	int	b;
	float	percent;

	percent = percentage(from->x, to->x, current->x);
	r = (int)((1 - percent) * ((from->color >> 16) & 0xFF)
		+ percent * ((to->color >> 16) & 0xFF));
	g = (int)((1 - percent) * ((from->color >> 8) & 0xFF)
		+ percent * ((to->color >> 8) & 0xFF));
	b = (int)((1 - percent) * ((from->color) & 0xFF)
		+ percent * ((to->color) & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

void	ft_put_pixel(t_pt *from, t_pt *to, t_pt *current, t_data *data)
{
	int	i;
	int	color;

	if (current->x > 0 && current->x < data->winwidth
		&& current->y > 0 && current->y < data->winheight)
	{
		i = (((int)(current->x) * (int)(data->bits_per_pixel / 8))
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
	int	max;

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

float	maxz(t_data *data)
{
	int	i;
	int	j;
	float	max;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (max < data->matrix[i][j])
				max = data->matrix[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

float	minz(t_data *data)
{
	int	i;
	int	j;
	float	min;

	min = maxz(data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (min > data->matrix[i][j])
				min = data->matrix[i][j];
			j++;
		}
		i++;
	}
	return (min);
}

void	make_pt(float x, float y, t_pt *pt, t_data *data)
{
	pt->z = data->matrix[(int)y][(int)x];
	pt->x = x;
	pt->y = y;
	if (pt->z == 0)
		pt->color = 0x0000FF;
	else
		pt->color = 0xFF0000;
//	pt->color = get_default_color(minz(data), maxz(data), pt->z, data);
	pt->z -= ((pt->z / 10) * data->z_scale) / 5;
	ft_project(pt, data);
}

void	draw(t_data *data)
{
	int	y;
	int	x;
	t_pt	*from;
	t_pt	*to;

	from = malloc(sizeof (t_pt));
	to = malloc(sizeof (t_pt));
	ft_bzero(data->addr, 1200 * 1800 * (data->bits_per_pixel / 8));
	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
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
		}
	}
	free(from);
	free(to);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
