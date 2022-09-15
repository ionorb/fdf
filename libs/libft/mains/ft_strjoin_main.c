/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:05:41 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:17:32 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2);

int	main(int ac, char **av)
{
	(void)ac;
	printf("strjoin: %s\n", ft_strjoin(av[1], av[2]));
	return (0);
}
