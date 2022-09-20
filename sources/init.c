/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:00 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/19 17:35:51 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_tallest(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->matrix[i][j] > data->tallest)
				data->tallest = data->matrix[i][j];
			j++;
		}
		i++;
	}
}

void	init_pos(t_data *data)
{
	data->x_offset = 12;
	data->y_offset = 8;
	data->z_scale = 10;
	data->ang_x = -0.5;
	data->ang_y = 0;
	data->ang_z = 0.8;
	data->zoom = 42;
	data->z_scale = 42;
	get_tallest(data);
}

t_data	*ft_init_data(char **av)
{
	t_data	*data;
	
	data = malloc(sizeof (t_data));
	read_file(av[1], data);
	write(1, "ban\n", 4);
	init_pos(data);
	data->winheight = ft_atoi(av[2]);
	data->winwidth = ft_atoi(av[3]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->winwidth, data->winheight, "howcanibehomophobic");
	data->img = mlx_new_image(data->mlx, data->winwidth, data->winheight);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), &(data->size_line), &(data->endian));
	return (data);
}
