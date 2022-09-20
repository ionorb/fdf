/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/20 21:24:44 by yridgway         ###   ########.fr       */
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
	if (data->img)
		free(data->img);
	if (data->addr)
		free(data->addr);
	free(data->mlx);
	free(data);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	data->is_pressed = 0;
	printf("button:%d, x:%d, y%d\n", button, x, y);
	return (0);
}

void	setup_controls(t_data *data)
{
	mlx_hook(data->win, 2, 1, key_press, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_hook(data->win, 4, 0, mouse_press, data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 4)
		return (0);
	data = ft_init_data(av);
	make_isometric(data);
	setup_controls(data);
//	draw(data);
//	mlx_hook(data->win, 2, 1, key_press, data);
//	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
	ft_freedata(data);
	return (0);
}
