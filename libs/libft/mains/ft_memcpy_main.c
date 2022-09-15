/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:14:52 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:16:34 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void *ft_memcpy(void *dest, void *src, size_t n);

int	main(int ac, char **av)
{
	char	*src = av[1];
	char	*dest = (src + 1);
	size_t	n = atoi(av[2]);

	(void)ac;
	if (av[3][0] == 'm')
	{
		printf("before:\ndest (memcpy): %s\nsrc: %s\n", dest, src);
		memcpy(dest, src, n);
		printf("after:\ndest (memcpy): %s\nsrc: %s\n", dest, src);
		return (0);
	}
	else if (av[3][0] == 'f')
	{
		printf("before:\ndest (ft_memcpy): %s\nsrc: %s\n", dest, src);
		ft_memcpy(dest, src, n);
		printf("after:\ndest (ft_memcpy): %s\nsrc: %s\n", dest, src);
		return (0);
	}
	printf("you fucked up");
	return (0);
}
