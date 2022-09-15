/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:52:09 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:12:42 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int ft_isascii(int c);

int	main(int ac, char **av)
{
	(void)ac;
	printf("isascii: %d\nft_isascii: %d", isascii(av[1][0]), ft_isascii(av[1][0]));
	return (0);
}

