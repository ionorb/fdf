/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:21:29 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/20 22:22:00 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_pt *pt, t_pt *save, t_data *data)
{
	save->y = pt->y;
	save->z = pt->z;
	pt->y = save->y * cos(data->ang_x) + save->z * sin(data->ang_x);
	pt->z = -save->y * sin(data->ang_x) + save->z * cos(data->ang_x);
}

void	rotate_y(t_pt *pt, t_pt *save, t_data *data)
{
	save->x = pt->x;
	pt->z = save->z * cos(data->ang_y) - save->x * sin(data->ang_y);
	pt->x = save->z * sin(data->ang_y) + save->x * cos(data->ang_y);
}

void	rotate_z(t_pt *pt, t_pt *save, t_data *data)
{
	pt->x = save->x * cos(data->ang_z) - save->y * sin(data->ang_z);
	pt->y = save->x * sin(data->ang_z) + save->y * cos(data->ang_z);
}
