/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:05:36 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/26 14:28:00 by yridgway         ###   ########.fr       */
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

	r = (int)((1 - percent) * ((start >> 16) & 0xFF) + percent
			* ((end >> 16) & 0xFF));
	g = (int)((1 - percent) * ((start >> 8) & 0xFF) + percent
			* ((end >> 8) & 0xFF));
	b = (int)((1 - percent) * ((start) & 0xFF) + percent
			* ((end) & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

int	get_color(t_pt *from, t_pt *to, t_pt *current)
{
	float	percent;

	if (ft_abs(from->x - to->x) > ft_abs(from->y - to->y))
		percent = ft_percentage(from->x, to->x, current->x);
	else
		percent = ft_percentage(from->y, to->y, current->y);
	return (make_color(percent, from->color, to->color));
}

int	get_default_color(int z, t_data *data)
{
	float	percent;

	percent = ft_percentage(data->minz, data->maxz, z);
	if (percent < 0.25)
		return (make_color(ft_percentage(0, 250, percent * 1000),
				BLUE, PURPLE));
	else if (percent < 0.5)
		return (make_color(ft_percentage(0, 500, percent * 1000),
				PURPLE, PINK));
	else if (percent < 0.75)
		return (make_color(ft_percentage(0, 750, percent * 1000),
				PINK, RED));
	else
		return (make_color(ft_percentage(0, 1000, percent * 1000),
				RED, YELLOW));
}
