/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/12 23:14:36 by yoel             ###   ########.fr       */
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
	free(data->matrix);
	free(data);
}

/*int	key_press(int key, void *data)
{
	printf("%d", key);
	return (0);
}*/

int	main(int ac, char **av)
{
	t_data	*data;
	float	*pts;
	int		i;

	i = 0;
	if (ac != 7)
		return (0);
	pts = malloc (4 * sizeof(float));
	data = malloc(sizeof(t_data));
	read_file(av[1], data);
	while (++i < 5)
		pts[i - 1] = (float)ft_atoi(av[i + 1]);
	data->zoom = ft_atoi(av[i + 1]);
	i = -1;
//	while (++i < 4)
//		printf("pts[%d]:%f\n", i, pts[i]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 800, 800, "urmom");
//	draw_line(pts, data);
	draw(data);
//	mlx_key_hook(data->win, deal_key, NULL);
//	mlx_loop(data->mlx);
	ft_display(data);
	ft_freedata(data);
	return (0);
}
