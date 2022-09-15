/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/15 00:29:17 by yoel             ###   ########.fr       */
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
	free(data->img);
	free(data->addr);
	free(data->matrix);
	free(data);
}

int	key_press(int key, t_data *data)
{
	ft_putnbr_fd(key, 1);
	write(1, "\n", 1);
	if (key == 65362)
		data->y_offset--;
	if (key == 65364)
		data->y_offset++;
	if (key == 65361)
		data->x_offset--;
	if (key == 65363)
		data->x_offset++;
	if (key == 100)
		data->x_angle++;
	if (key == 97)
		data->x_angle--;
	if (key == 115)
		data->y_angle++;
	if (key == 119)
		data->y_angle--;
	if (key == 53)
		data->run = 0;
	if (key == 45)
		data->z_scale--;
	if (key == 61)
		data->z_scale++;
	if (key == 24)
		data->zoom++;
	if (key == 27)
		data->zoom--;
	mlx_clear_window(data->mlx, data->win);
//	mlx_destroy_image(data->mlx, data->img);
//	free(data->img);
//	data->img = mlx_new_image(data->mlx, 800, 800);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), &(data->size_line), &(data->endian));
	draw(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
//	int		i;

//	i = 0;
	if (ac != 8)
		return (0);
	data = malloc(sizeof(t_data));
	read_file(av[1], data);
	data->run = 1;
	data->zoom = ft_atoi(av[2]);
	data->x_offset = ft_atoi(av[3]);
	data->y_offset = ft_atoi(av[4]);
	data->z_scale = ft_atoi(av[5]);
	data->x_angle = ft_atoi(av[6]);
	data->y_angle = ft_atoi(av[7]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 800, "urmom");
	data->img = mlx_new_image(data->mlx, 800, 800);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel), &(data->size_line), &(data->endian));
	ft_display(data);
/*	while (i < 800 * 4 * 800)
	{	
		data->addr[i] = mlx_get_color_value(data->mlx, 255);
		data->addr[i + 1] = mlx_get_color_value(data->mlx, 255);
		data->addr[i + 2] = mlx_get_color_value(data->mlx, 255);
		i += 4;
	}*/
//	ft_putnbr_fd(data->endian, 1);
//	write(1, "\n", 1);
//	ft_putnbr_fd(data->bits_per_pixel / 8, 1);
//	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	draw(data);
	mlx_key_hook(data->win, key_press, data);
	mlx_loop(data->mlx);
	ft_freedata(data);
	return (0);
}
