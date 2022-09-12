/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/09/12 02:45:55 by yoel             ###   ########.fr       */
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

void	draw_line(float x0, float y0, float x1, float y1, t_data *data)
{
	float	grad;
	float	x;
	float	y;

	if (y1 - y0 == 0)
		grad = 1;
	else
		grad = ft_abs(x1 - x0) / ft_abs(y1 - y0);
	printf("grad:%f\n", grad);
	y = y0;
	x = x0;
	if (x1 >= x0 && y1 >= y0)
	{
		while (y <= y1)
		{
        	mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);//plot(x, y)
			x += grad;
			y += 1;
		}
	}
	else if (x1 <= x0 && y1 >= y0)
	{
		while (y <= y1)
		{
        	mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);//plot(x, y)
			x -= grad;
			y += 1;
		}
	}
	else if (x1 >= x0 && y1 <= y0)
	{
		while (y <= y1)
		{
        	mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);//plot(x, y)
			x += grad;
			y -= 1;
		}
	}
	else if (x1 <= x0 && y1 <= y0)
	{
		while (y <= y1)
		{
        	mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);//plot(x, y)
			x -= grad;
			y -= 1;
		}
	}
	printf("x:%f y:%f\n", x, y);
}
