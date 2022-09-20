/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:05:36 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/20 21:41:25 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_percentage(int start, int end, int current)
{
	float	current_loc;
	float	distance;

	current_loc = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	return (current_loc / distance);
}

int	make_color(float percent, int start, int end)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - percent) * ((start >> 16) & 0xFF) + percent * ((end >> 16) & 0xFF));
	g = (int)((1 - percent) * ((start >> 8) & 0xFF) + percent * ((end >> 8) & 0xFF));
	b = (int)((1 - percent) * ((start) & 0xFF) + percent * ((end) & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

int	get_color(t_pt *from, t_pt *to, t_pt *current)
{
//	int	r;
//	int	g;
//	int	b;
	float	percent;

	if (ft_abs(from->x - to->x) > ft_abs(from->y - to->y))
		percent = ft_percentage(from->x, to->x, current->x);
	else
		percent = ft_percentage(from->y, to->y, current->y);
/*	r = (int)((1 - percent) * ((from->color >> 16) & 0xFF) + percent * ((to->color >> 16) & 0xFF));
	g = (int)((1 - percent) * ((from->color >> 8) & 0xFF) + percent * ((to->color >> 8) & 0xFF));
	b = (int)((1 - percent) * ((from->color) & 0xFF) + percent * ((to->color) & 0xFF));
	r = make_color(percent, (from->color >> 16) & 0xFF,
		(to->color >> 16) & 0xFF);
	g = make_color(percent, (from->color >> 8) & 0xFF,
		(to->color >> 8) & 0xFF);
	b = make_color(percent, (from->color) & 0xFF,
		(to->color) & 0xFF);*/
	return (make_color(percent, from->color, to->color));//(r << 16) | (g << 8) | b);
}

int	get_default_color(int z, t_data *data)
{
	float	percent;

	percent = ft_percentage(minz(data), maxz(data), z);
	if (percent < 0.333)
		return (make_color(percent(0, 333, ), 0x0000FF, 0xFF00FF));
	else if (percent < 0.666)
		return (make_color(percent, 0xFF00FF, 0xFF0000));
	else //if (percent < 0.75)
		return (make_color(percent, 0xFF0000, 0xFFFF00));
//	else
//		return (0xFFFFFF);
}
