/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:28:26 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:17:52 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len);

int	main(int ac, char **av)
{
	(void)ac;
	printf("ft_strnstr:\t%s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	return (0);
}
