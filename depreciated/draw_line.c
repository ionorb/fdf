/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:41:58 by yoel              #+#    #+#             */
/*   Updated: 2022/09/12 02:09:37 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
		return (num *= -1);
	return (num);
}

void	plotlow(int x0, int y0, int x1, int y1, t_data *data)
{
	int	dx;
	int	dy;
	int	yi;
	int	x;
	int	y;
	int	D;

	dx = x1 - x0;
    dy = y1 - y0;
    yi = 1;
    if (dy < 0)
	{
		yi = -1;
        dy = -dy;
	}
    D = (2 * dy) - dx;
    y = y0;
	x = x0;
    while(x <= x1)
	{
        mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);//plot(x, y)
        if (D > 0)
		{
            y = y + yi;
            D = D + (2 * (dy - dx));
		}
        else
            D = D + 2 * dy;
		x++;
	}
}

void	plothigh(int x0, int y0, int x1, int y1, t_data *data)
{
	int	dx;
	int	dy;
	int	xi;
	int	x;
	int	y;
	int	D;

	dx = x1 - x0;
    dy = y1 - y0;
    xi = 1;
    if (dx < 0)
	{
		xi = -1;
        dx = -dx;
	}
    D = (2 * dx) - dy;
    y = y0;
	x = x0;
    while(y <= y1)
	{
        mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);//plot(x, y)
        if (D > 0)
		{
            x = x + xi;
            D = D + (2 * (dx - dy));
		}
        else
            D = D + 2 * dx;
		y++;
	}
}

void	draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
	if (ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if (x0 > x1)
			plotlow(x1, y1, x0, y0, data);
		else
			plotlow(x0, y0, x1, y1, data);
	}
	else
	{
		if (y0 > y1)
			plothigh(x1, y1, x0, y0, data);
		else
			plothigh(x0, y0, x1, y1, data);
	}
}
