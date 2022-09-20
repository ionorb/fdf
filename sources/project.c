/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:08:29 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/19 17:02:54 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_pt *pt, t_pt *save, t_data *data)
{
	save->y = pt->y;
	save->z = pt->z;
	//printf("[data->ang_x:%f\n", data->ang_x);
	//printf("\n\n\n\n\nz:%f\n\n\n\n\n\n\n", pt->z);
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

t_data	*cpy_struc(t_data *data)
{
	t_data	*cpy;

	cpy = malloc(sizeof (t_data));
	cpy->x_offset = data->x_offset;
	cpy->y_offset = data->y_offset;
	cpy->ang_x = data->ang_x;
	cpy->ang_y = data->ang_y;
	cpy->ang_z = data->ang_z;
	cpy->zoom = data->zoom;
	cpy->z_scale = data->z_scale;
	return (cpy);
}

void	make_isometric(t_data *data)
{
	int	i;
	t_data	*cpy;

	cpy = cpy_struc(data);
	i = 0;
	while (i < 10)
	{
		printf("xoff:%d yoff:%d zoom:%f scale:%d \n", data->x_offset, data->y_offset, data->zoom, data->z_scale);
		data->x_offset += (12 - cpy->x_offset) / 10;
		data->y_offset += (8 - cpy->y_offset) / 10;
		data->ang_x += (-0.5 - cpy->ang_x) / 10;
		data->ang_y += (0 - cpy->ang_y) / 10;
		data->ang_z += (0.8 - cpy->ang_z) / 10;
		data->zoom += (42 - cpy->zoom) / 10;
		data->z_scale += (42 - cpy->z_scale) / 10;
		data->img = mlx_new_image(data->mlx, 1800, 1200);
		data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), &(data->size_line), &(data->endian));
		draw(data);
		i++;
	}
	free(cpy);
/*		data->x_offset = 12;
		data->y_offset = 8;
		data->z_scale = 10;
		data->ang_x = -0.5;
		data->ang_y = 0;
		data->ang_z = 0.8;
		data->zoom = 42;
		data->z_scale = 42;*/
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
    save->x = pt->x - origin->x;
    save->y = pt->y - origin->y;
    save->z = pt->z;
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
