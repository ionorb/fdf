/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/29 01:03:04 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_data *data)
{
	data->mousex = x;
	data->mousey = y;
	if (button == 4)
	{
			data->x_offset -= (data->mousex - data->prev_mousex) / data->zoom;
			data->y_offset -= (data->mousey - data->prev_mousey) / data->zoom;
			data->zoom++;
	}
	if (button == 5)
	{
			data->x_offset -= (data->mousex - data->prev_mousex) / data->zoom;
			data->y_offset -= (data->mousey - data->prev_mousey) / data->zoom;
			data->zoom--;
	}
	draw(data);
	data->prev_mousex = x;
	data->prev_mousey = y;
	return (0);
}

void	setup_controls(t_data *data)
{
	mlx_mouse_hook(data->win, mouse_press, data);
	mlx_hook(data->win, 2, 1, key_press, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = ft_init_data(av);
	setup_controls(data);
	draw(data);
	mlx_loop(data->mlx);
	return (0);
}
