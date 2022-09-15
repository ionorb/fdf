/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:36:57 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:12:29 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void bzero(void *s, size_t n);

int	main(int ac, char **av)
{
		char	*str1 = av[1];
		char	*str2 = av[2];

		if (ac == 3)
		{
				printf("before erase:\nstr1: %s\nstr2: %s\n\n", str1, str2);
				bzero(str1);
				printf("after erase:\nstr1 (bzero): %s\nstr2 (ft_bzero): %s\n", str1, str2);
				return (0);
		}
		printf("you fucked it");
		return (0);
}
