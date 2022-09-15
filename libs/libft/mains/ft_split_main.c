/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:51:36 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:16:43 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	**ft_split(char const *s, char c);

int	main(int ac, char **av)
{
	int	i = 0;
	char	**arr = ft_split(av[1], av[2][0]);

	(void)ac;
	while (arr[i])
	{
		printf("arr[%d]:\t%s\n", i, arr[i]);
		i++;
	}
	return (0);
}
