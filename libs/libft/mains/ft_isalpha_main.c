/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:49:11 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:12:39 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int ft_isalpha(int c);

int	main(int ac, char **av)
{
	(void)ac;
	
	int	c = av[1][0];

	printf("isalpha: %d\nft_isalpha: %d", isalpha(c), ft_isalpha(c));
	return (0);
}
