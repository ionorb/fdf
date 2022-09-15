/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:19:00 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:16:38 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void *ft_memset(void *s, int c, size_t n);

int	main(int ac, char **av)
{
	char	*str1;
	char	*str2;
	int	c;
	
	if (ac == 5)
	{
		str1 = av[1];
		str2 = av[2];
		c = atoi(av[3]);

		memset(str1, av[4][0], c);
		ft_memset(str2, av[4][0], c);
		printf("memset: %s\nft_memset: %s", str1, str2);
	}
	else
		printf("\nYou fucked it\n");
	return (0);
}
