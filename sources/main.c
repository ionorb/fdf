/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/21 16:48:21 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
//	make_isometric(data);
	setup_controls(data);
	mlx_loop(data->mlx);
	ft_freedata(data);
	return (0);
}
