/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:41:50 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/20 22:23:48 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(int n)
{
	long	num;

	num = (long)n;
	if (num < 0)
		return (num *= -1);
	return (num);
}

int	get_max(float a, float b)
{
	int	max;

	if (ft_abs(a) >= ft_abs(b))
		max = (int)ft_abs(a);
	else
		max = (int)ft_abs(b);
	return (max);
}

float	maxz(t_data *data)
{
	int		i;
	int		j;
	float	max;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (max < data->matrix[i][j])
				max = data->matrix[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

float	minz(t_data *data)
{
	int		i;
	int		j;
	float	min;

	min = maxz(data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (min > data->matrix[i][j])
				min = data->matrix[i][j];
			j++;
		}
		i++;
	}
	return (min);
}
