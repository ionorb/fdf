/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:26 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/11 17:42:42 by myaccount        ###   ########.fr       */
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
			printf("%d ", data->matrix[i][j]);
			if (data->matrix[i][j] < 10 && data->matrix[i][j] > -1)
				printf(" ");
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

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac > 2)
		return (0);
	data = malloc(sizeof(t_data));
	read_file(av[1], data);
	ft_display(data);
	ft_freedata(data);
	return (0);
}
