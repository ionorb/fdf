/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:11:52 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/28 16:16:24 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_offset(int key, t_data *data)
{
	if (key == 65362)
		data->y_offset -= data->scaler * data->scaler / 2 * 0.1;
	if (key == 65364)
		data->y_offset += data->scaler * data->scaler / 2 * 0.1;
	if (key == 65361)
		data->x_offset -= data->scaler * data->scaler / 2 * 0.1;
	if (key == 65363)
		data->x_offset += data->scaler * data->scaler / 2 * 0.1;
	if (key >= 49 && key <= 57)
		data->scaler = key - 48;
	printf("y_off:%f, x_off:%f\n", data->y_offset, data->x_offset);
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
	printf("x:%f, y:%f, z:%f\n", data->ang_x, data->ang_y, data->ang_z);
}

void	ft_scale(int key, t_data *data)
{
	if (key == 44)
		data->z_scale += 0.5;
	if (key == 46)
		data->z_scale -= 0.5;
	if (key == 65307)
		ft_close(data);
	printf("z_scale:%f\n", data->z_scale);
}

void	ft_zoom(int key, t_data *data)
{
	if (key == 61)
		data->zoom++;
	if (key == 45)
		data->zoom--;
	printf("zoom:%f\n", data->zoom);
	printf("width:%d, height:%d\n", data->width, data->height);
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
