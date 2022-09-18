/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/16 17:10:08 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_display(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (data->matrix[i][j] < 10 && data->matrix[i][j] > -1)
				printf("   %d", data->matrix[i][j]);
			else if ((data->matrix[i][j] > 9 && data->matrix[i][j] < 100)
				|| (data->matrix[i][j] < 0 && data->matrix[i][j] > -10))
				printf("  %d", data->matrix[i][j]);
			else
				printf(" %d", data->matrix[i][j]);
		}
		printf("\n");
		i++;
	}
}

void	ft_freedata(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->matrix[i]);
		i++;
	}
	free(data->mlx);
	free(data->win);
//	free(data->img);
//	free(data->addr);
	free(data->matrix);
	free(data);
}

int	key_press(int key, t_data *data)
{
	ft_putnbr_fd(key, 1);
	write(1, "\n", 1);
	ft_offset(key, data);
	ft_angle(key, data);
	ft_scale(key, data);
	ft_zoom(key, data);
	mlx_clear_window(data->mlx, data->win);
//	mlx_destroy_image(data->mlx, data->img);
//	free(data->img);
//	data->img = mlx_new_image(data->mlx, 800, 800);
	printf("ang_x:%f, ang_y:%f, ang_z%f\n", data->ang_x, data->ang_y, data->ang_z);
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;
	int		j;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_data));
	read_file(av[1], data);
	data->tallest = 0;
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
	data->zoom = 10;
	data->x_offset = 0;
	data->y_offset = 0;
	data->z_scale = 10;
	data->ang_x = 0;//.523599;
	data->ang_y = 0;//.523599;
	data->ang_z = 0;//.523599;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 800, "howcanibehomophobic");
	data->img = mlx_new_image(data->mlx, 800, 800);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), &(data->size_line), &(data->endian));
	draw(data);
	//return (0);
	mlx_key_hook(data->win, key_press, data);
	mlx_loop(data->mlx);
	ft_freedata(data);
	return (0);
}
