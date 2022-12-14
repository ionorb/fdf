/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:00 by yridgway          #+#    #+#             */
/*   Updated: 2022/10/13 15:48:35 by yridgway         ###   ########.fr       */
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

void	ft_exit(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(0);
}

int	ft_close(void *data)
{
	ft_freedata(data);
	free(data);
	ft_exit("program exited correctly :)");
	return (0);
}

void	init_pos(t_data *data)
{
	data->x_offset = ((data->winwidth / 2) / (data->winwidth
				/ (data->width * 1.5)) - (data->width / 2));
	data->y_offset = ((data->winheight / 2) / (data->winwidth
				/ (data->width * 1.5)) - (data->height / 2));
	data->ang_x = 5.5;
	data->ang_y = 0;
	data->ang_z = 0.8;
	data->zoom = data->winwidth / (data->width * 1.5);
	data->z_scale = 42;
	data->centrex = data->winwidth / 2;
	data->centrey = data->winheight / 2;
	data->prev_mousex = 0;
	data->prev_mousey = 0;
	data->mousex = 0;
	data->mousey = 0;
}

t_data	*ft_init_data(char **av)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		ft_exit("problem with malloc of: 'data' variable");
	read_file(av[1], data);
	data->winwidth = 1200;
	data->winheight = 1200;
	init_pos(data);
	data->scaler = 1;
	data->maxz = maxz(data);
	data->minz = minz(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->winwidth, \
			data->winheight, "fdf");
	data->img = mlx_new_image(data->mlx, data->winwidth, data->winheight);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->size_line), &(data->endian));
	return (data);
}
