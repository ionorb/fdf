/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:05:36 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/20 19:18:06 by yridgway         ###   ########.fr       */
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

	if (ft_abs(from->x - to->x) > ft_abs(from->y - to->y))
		percent = percentage(from->x, to->x, current->x);
	else
		percent = percentage(from->y, to->y, current->y);
	r = (int)((1 - percent) * ((from->color >> 16) & 0xFF)
		+ percent * ((to->color >> 16) & 0xFF));
	g = (int)((1 - percent) * ((from->color >> 8) & 0xFF)
		+ percent * ((to->color >> 8) & 0xFF));
	b = (int)((1 - percent) * ((from->color) & 0xFF)
		+ percent * ((to->color) & 0xFF));
	return ((r << 16) | (g << 8) | b);
}

int	get_default_color(int z, t_data *data)
{
	float	percent;

	percent = percentage(minz(data), maxz(data), z);
	if (percent < 0.25)
		return (0x0000FF);
	else if (percent < 0.5)
		return (0xFFFF00);
	else if (percent < 0.75)
		return (0x00FF00);
	else
		return (0xFFFFFF);
}
