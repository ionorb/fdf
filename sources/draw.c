/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 02:22:45 by yoel              #+#    #+#             */
/*   Updated: 2022/10/13 15:25:50 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_pt *from, t_pt *to, t_pt *current, t_data *data)
{
	int	i;
	int	color;

	if (current->x > 0 && current->x < data->size_line / 4 && current->y > 0
		&& current->y < data->winheight)
	{
		i = (((int)(current->x) * (data->bits_per_pixel / 8))
				+ ((int)(current->y) * (int)(data->size_line)));
		color = get_color(from, to, current);
		data->addr[i] = color;
		data->addr[i + 1] = color >> 8;
		data->addr[i + 2] = color >> 16;
	}
}

void	draw_line(t_pt *from, t_pt *to, t_data *data)
{
	float	dx;
	float	dy;
	float	step;
	t_pt	*current;
	int		i;

	current = malloc(sizeof (t_pt));
	dx = (to->x - from->x);
	dy = (to->y - from->y);
	if (ft_abs(dx) >= ft_abs(dy))
		step = ft_abs(dx);
	else
		step = ft_abs(dy);
	dx = dx / step;
	dy = dy / step;
	current->x = from->x;
	current->y = from->y;
	i = -1;
	while (++i < step)
	{
		ft_put_pixel(from, to, current, data);
		current->x = current->x + dx;
		current->y = current->y + dy;
	}
	free(current);
}

void	draw(t_data *data)
{
	t_pt	*from;
	t_pt	*to;
	int		invert;

	from = malloc(sizeof (t_pt));
	to = malloc(sizeof (t_pt));
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->winwidth, data->winheight);
	data->addr = mlx_get_data_addr(data->img,
			&(data->bits_per_pixel), &(data->size_line), &(data->endian));
	invert = get_inversion(data);
	if (invert == 1)
		make_grid(from, to, data);
	else
		make_grid_rev(from, to, data);
	free(from);
	free(to);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
