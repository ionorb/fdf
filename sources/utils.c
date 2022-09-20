/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:41:50 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/19 17:42:22 by yridgway         ###   ########.fr       */
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
