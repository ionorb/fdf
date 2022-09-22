/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:41:58 by yoel              #+#    #+#             */
/*   Updated: 2022/09/22 17:26:44 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plotlow(t_pt *from, t_pt *to, t_data *data)
{
	int	dx;
	int	dy;
	int	yi;
	int	D;
	t_pt *current;

	current = malloc(sizeof (t_pt));
	dx = to->x - from->x;
    dy = to->y - from->y;
    yi = 1;
    if (dy < 0)
	{
		yi = -1;
        dy = -dy;
	}
    D = (2 * dy) - dx;
    current->y = from->y;
	current->x = from->x;
    while(current->x <= to->x)
	{
		ft_put_pixel(from, to, current, data);
        if (D > 0)
		{
            current->y = current->y + yi;
            D = D + (2 * (dy - dx));
		}
        else
            D = D + 2 * dy;
		current->x++;
	}
	free(current);
}

void	plothigh(t_pt *from, t_pt *to, t_data *data)
{
	int	dx;
	int	dy;
	int	xi;
	int	D;
	t_pt *current;

	current = malloc(sizeof (t_pt));
	dx = to->x - from->x;
    dy = to->y - from->y;
    xi = 1;
    if (dx < 0)
	{
		xi = -1;
        dx = -dx;
	}
    D = (2 * dx) - dy;
    current->y = from->y;
	current->x = from->x;
    while(current->y <= to->y)
	{
		ft_put_pixel(from, to, current, data);
        if (D > 0)
		{
            current->x = current->x + xi;
            D = D + (2 * (dx - dy));
		}
        else
            D = D + 2 * dx;
		current->y++;
	}
	free(current);
}

void	draw_line_v2(t_pt *from, t_pt *to, t_data *data)
{
	if (ft_abs(to->y - from->y) < ft_abs(to->x - from->x))
	{
		if (from->x > to->x)
			plotlow(to, from, data);
		else
			plotlow(from, to, data);
	}
	else
	{
		if (from->y > to->y)
			plothigh(to, from, data);
		else
			plothigh(from, to, data);
	}
}
