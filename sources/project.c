/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:08:29 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/18 00:08:30 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_pt *pt, t_pt *save, t_data *data)
{
	save->y = pt->y;
    save->z = pt->z;
	//printf("[data->ang_x:%f\n", data->ang_x);
	pt->y = save->y * cos(data->ang_x) + save->z * sin(data->ang_x);
	pt->z = -save->y * sin(data->ang_x) + save->z * cos(data->ang_x);
}

void	rotate_y(t_pt *pt, t_pt *save, t_data *data)
{
	save->x = pt->x;
	//printf("[data->ang_y:%f\n", data->ang_y);
	pt->z = save->z * cos(data->ang_y) - save->x * sin(data->ang_y);
    pt->x = save->z * sin(data->ang_y) + save->x * cos(data->ang_y);
}

void	rotate_z(t_pt *pt, t_pt *save, t_data *data)
{
	pt->x = save->x * cos(data->ang_z) - save->y * sin(data->ang_z);
	pt->y = save->x * sin(data->ang_z) + save->y * cos(data->ang_z);
}

void	make_isometric(t_pt *pt, t_data *data)
{
	float	previous_x;
	float	previous_y;

	previous_x = pt->x;
	previous_y = pt->y;
	pt->x = (previous_x - previous_y) * cos(0.523599);
	pt->y = -pt->z * data->z_scale / 10 + (previous_x + previous_y) * sin(0.523599);
}

void	ft_project(t_pt *pt, t_data *data)
{
    t_pt    *save;
    t_pt    *origin;

    origin = malloc(sizeof (t_pt));
    save = malloc(sizeof (t_pt));
    origin->x = data->width / 2 + data->x_offset;
    origin->y = data->height / 2 + data->y_offset;
    origin->z = 0;
	pt->x += data->x_offset;
	pt->y += data->y_offset;
	//make_isometric(pt, data);
    save->x = pt->x - origin->x;
    save->y = pt->y - origin->y;
    // ft_putnbr_fd((int)pt->x, 1);
    // write(1, "\n", 1);
    // ft_putnbr_fd((int)pt->y, 1);
    // write(1, "\n", 1);
    // ft_putnbr_fd((int)pt->z, 1);
    // write(1, "\n", 1);
    rotate_z(pt, save, data);
	rotate_y(pt, save, data);
	rotate_x(pt, save, data);
    // ft_putnbr_fd((int)pt->x, 1);
    // write(1, "\n", 1);
    // ft_putnbr_fd((int)pt->y, 1);
    // write(1, "\n", 1);
    // ft_putnbr_fd((int)pt->z, 1);
    // write(1, "\n", 1);
    pt->x += origin->x;
    pt->y += origin->y;
	pt->x *= data->zoom;
	pt->y *= data->zoom;
}