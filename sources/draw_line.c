/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:41:58 by yoel              #+#    #+#             */
/*   Updated: 2022/09/24 16:25:58 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plotlow(t_pt *from, t_pt *to, t_data *data)
{
	int		dx;
	int		dy;
	int		yi;
	int		d;
	t_pt	*current;

	current = malloc(sizeof (t_pt));
	dx = to->x - from->x;
	dy = to->y - from->y;
	yi = 1;
	if (dy < 0)
	{
		yi = -yi;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	current->y = from->y;
	current->x = from->x;
	while (current->x <= to->x)
	{
		ft_put_pixel(from, to, current, data);
		if (d > 0)
		{
			current->y = current->y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		current->x++;
	}
	free(current);
}

void	plothigh(t_pt *from, t_pt *to, t_data *data)
{
	int		dx;
	int		dy;
	int		xi;
	int		d;
	t_pt	*current;

	current = malloc(sizeof (t_pt));
	dx = to->x - from->x;
	dy = to->y - from->y;
	xi = 1;
	if (dx < 0)
	{
		xi = -xi;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	current->y = from->y;
	current->x = from->x;
	while (current->y <= to->y)
	{
		ft_put_pixel(from, to, current, data);
		if (d > 0)
		{
			current->x = current->x + xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
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
