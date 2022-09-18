/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:11:52 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/17 18:11:55 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_offset(int key, t_data *data)
{
    if (key == 65362)
        data->y_offset--;
    if (key == 65364)
        data->y_offset++;
    if (key == 65361)
        data->x_offset--;
    if (key == 65363)
        data->x_offset++;
}

void    ft_angle(int key, t_data *data)
{
	if (key == 97 || key == 115)
	{
		if (key == 97)
			data->ang_x -= 0.1;
		if (key == 115)
			data->ang_x += 0.1;
		data->change_x = 1;
	}
	else
		data->change_x = 0;
	if (key == 100 || key == 102)
	{
		if (key == 100)
			data->ang_y -= 0.1;
		if (key == 102)
			data->ang_y += 0.1;
		data->change_y = 1;
	}
	else
		data->change_y = 0;
	if (key == 103 || key == 104)
	{
		if (key == 103)
			data->ang_z -= 0.1;
		if (key == 104)
			data->ang_z += 0.1;
		data->change_z = 1;
	}
	else
		data->change_z = 0;
}

void    ft_scale(int key, t_data *data)
{
	if (key == 46)
		data->z_scale++;
	if (key == 44)
		data->z_scale--;
}
void    ft_zoom(int key, t_data *data)
{
	if (key == 61)
		data->zoom++;
	if (key == 45)
		data->zoom--;
}