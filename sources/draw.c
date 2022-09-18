/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/16 17:13:56 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
		return (num *= -1);
	return (num);
}

float	*arr_cpy(float *arr, int size, int zoom)
{
	int		i;
	float	*cpy;

	cpy = malloc(size * sizeof (float));
	i = 0;
	while (i < size)
	{
		cpy[i] = arr[i] * zoom;
		i++;
	}
	return (cpy);
}



int		get_max(float a, float b)
{
	int	max;

	if (ft_abs(a) >= ft_abs(b))
		max = (int)ft_abs(a);
	else
		max = (int)ft_abs(b);
	return (max);
}

int	get_color(t_pt *from, t_pt *to, t_data *data)
{
	int	color;

	color = 0xffffff;
	if (from->z == data->tallest || to->z == data->tallest)
		color = 0x800000;
	return (color);
}

void	ft_put_pixel(t_pt *from, t_pt *to, t_data *data)
{
	int	i;
	int	color;

    // ft_putnbr_fd((int)from->x, 1);
    // write(1, "\n", 1);
    // ft_putnbr_fd((int)from->y, 1);
    // write(1, "\n", 1);
    // ft_putnbr_fd((int)from->z, 1);
    // write(1, "\n", 1);
	printf("x:%f, y:%f, z:%f\n", from->x, from->y, from->z);
	if (from->x >= 0 && from->x < 800 * (data->bits_per_pixel / 8) && from->y >= 0 && from->y <= 800)
	{
		i = (((int)(from->x) * (int)(data->bits_per_pixel / 8)) + ((int)(from->y) * (int)(data->size_line)));
//		mlx_pixel_put(data->mlx, data->win, from->x, from->y, 255);
		color = get_color(from, to, data);
		data->addr[i] = color;
		data->addr[i + 1] = color >> 8;
		data->addr[i + 2] = color >> 16;
	}
}

void	draw_line(t_pt *from, t_pt *to, t_data *data)
{
	float	xstep;
	float	ystep;
	int		max;

	xstep = to->x - from->x;
	ystep = to->y - from->y;
	max = get_max(xstep, ystep);
	xstep /= max;
	ystep /= max;
	while ((int)(from->x - to->x) || (int)(from->y - to->y))
	{
		//printf("ban\n");
		ft_put_pixel(from, to, data);
		from->x += xstep;
		from->y += ystep;
	}
}

void	make_pt(float x, float y, t_pt *pt, t_data *data)
{
	pt->z = data->matrix[(int)y][(int)x];
	pt->x = x;
	pt->y = y;
	ft_project(pt, data);
	//pt->x += 3744;
	//pt->y += 3800;
}

void	draw(t_data *data)
{
	int		y;
	int		x;
	t_pt	*from;
	t_pt	*to;

	from = malloc(sizeof (t_pt));
	to = malloc(sizeof (t_pt));
	//data->ang_x = 0;
	//data->ang_y = 0;
	//data->ang_z = 0;
	ft_bzero(data->addr, 800 * 800 * (data->bits_per_pixel / 8));
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
			x += 1;
		}
		y += 1;
	}
	free(from);
	free(to);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
