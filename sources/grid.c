/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:56:02 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/10 15:59:09 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	get_inversion(t_data *data)
{
	int	invert;

	invert = 1;
	if (data->ang_z > 1.7 && data->ang_z < 3 * PI / 2)
			invert *= -1;
	if (data->ang_x > 0 && data->ang_x < PI)
			invert *= -1;
	return (invert);
}
