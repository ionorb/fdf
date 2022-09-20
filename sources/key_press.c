/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:11:52 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/20 22:16:44 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_offset(int key, t_data *data)
{
	if (key == 65362)
		data->y_offset -= 0.1;
	if (key == 65364)
		data->y_offset += 0.1;
	if (key == 65361)
		data->x_offset -= 0.1;
	if (key == 65363)
		data->x_offset += 0.1;
}

void	ft_angle(int key, t_data *data)
{
	if (key == 119)
		data->ang_x -= 0.1;
	if (key == 115)
		data->ang_x += 0.1;
	if (key == 97)
		data->ang_y -= 0.1;
	if (key == 100)
		data->ang_y += 0.1;
	if (key == 113)
		data->ang_z -= 0.1;
	if (key == 101)
		data->ang_z += 0.1;
}

void	ft_scale(int key, t_data *data)
{
	if (key == 44)
		data->z_scale += 0.5;
	if (key == 46)
		data->z_scale -= 0.5;
	if (key == 65307)
		ft_close(data);
}

void	ft_zoom(int key, t_data *data)
{
	if (key == 61)
		data->zoom++;
	if (key == 45)
		data->zoom--;
}

int	key_press(int key, t_data *data)
{
	ft_offset(key, data);
	ft_angle(key, data);
	ft_scale(key, data);
	ft_zoom(key, data);
	if (key == 105)
		make_isometric(data);
	draw(data);
	return (0);
}
