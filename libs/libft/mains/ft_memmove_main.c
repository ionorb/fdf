/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:14:52 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:16:36 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void *ft_memmove(void *dest, const void *src, size_t n);

int	main(int ac, char **av)
{
	char	*src = av[1];
	char	*dest = (src + 2);
	size_t	n = atoi(av[2]);

	(void)ac;
	if (av[3][0] == 'm')
	{
		memmove(dest, src, n);
		printf("dest (memmove): %s\nsrc: %s\n", dest, src);
		return (0);
	}
	else if (av[3][0] == 'f')
	{
		ft_memmove(dest, src, n);
		printf("dest (ft_memmove): %s\nsrc: %s\n", dest, src);
		return (0);
	}
	printf("you fucked up");
	return (0);
}
