/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:11:00 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/24 15:44:16 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freedata(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	free(data->win);
	free(data->mlx);
	free(data);
	printf("boo\n");
}

int	ft_close(void *data)
{
	ft_freedata(data);
	(void)data;
	exit(0);
}

void	init_pos(t_data *data)
{
	data->x_offset = 0;
	data->y_offset = 0;
	data->z_scale = 0;
	data->ang_x = 0;
	data->ang_y = 0;
	data->ang_z = 0;
	data->zoom = 0;
	data->z_scale = 0;
}

t_data	*ft_init_data(char **av)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	read_file(av[1], data);
	init_pos(data);
	data->winwidth = ft_atoi(av[2]);
	data->winheight = ft_atoi(av[3]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->winwidth, data->winheight,
			"howcanibehomophobic");
	data->img = mlx_new_image(data->mlx, data->winwidth, data->winheight);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->size_line), &(data->endian));
	printf("bananaooooooooooooooo\n");
	return (data);
}
