/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/19 00:51:46 by yridgway         ###   ########.fr       */
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
	free(data->mlx);
	free(data->win);
	if (data->img)
		free(data->img);
	if (data->addr)
		free(data->addr);
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
	draw(data);
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	data->is_pressed = 0;
	printf("button:%d, x:%d, y%d\n", button, x, y);
	return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

void	setup_controls(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_hook(data->win, 4, 0, mouse_press, data);
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
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1800, 1200, "howcanibehomophobic");
	data->img = mlx_new_image(data->mlx, 1800, 1200);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), &(data->size_line), &(data->endian));
	data->x_offset = 12;
	data->y_offset = 8;
	data->z_scale = 10;
	data->ang_x = -0.5;
	data->ang_y = 0;
	data->ang_z = 0.8;
	data->zoom = 42;
	data->z_scale = 42;
//	make_isometric(data);
	draw(data);
	mlx_hook(data->win, 2, 1, key_press, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
	ft_freedata(data);
	return (0);
}
