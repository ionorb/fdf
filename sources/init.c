/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:00 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/29 00:45:15 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freedata(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	ft_close(void *data)
{
	ft_freedata(data);
	free(data);
	exit(0);
}

void	init_pos(t_data *data)
{
	data->x_offset = ((data->winwidth / 2) / (data->winwidth
				/ (data->width * 1.5)) - (data->width / 2));
	data->y_offset = ((data->winheight / 2) / (data->winwidth
				/ (data->width * 1.5)) - (data->height / 2));
	data->ang_x = -0.9;
	data->ang_y = 0;
	data->ang_z = 0.8;
	data->zoom = data->winwidth / (data->width * 1.5);
	data->z_scale = 42;
	data->centrex = data->winwidth / 2;
	data->centrey = data->winheight / 2;
	data->prev_mousex = 0;//data->centrex;
	data->prev_mousey = 0;//data->centrey;
}

t_data	*ft_init_data(char **av)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	read_file(av[1], data);
	data->winwidth = 1800;
	data->winheight = 1200;
	init_pos(data);
	data->scaler = 1;
	data->maxz = maxz(data);
	data->minz = minz(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->winwidth, data->winheight,
			"howcanibehomophobic");
	data->img = mlx_new_image(data->mlx, data->winwidth, data->winheight);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->size_line), &(data->endian));
	return (data);
}
