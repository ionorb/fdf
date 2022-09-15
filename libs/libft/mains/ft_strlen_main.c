/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:06:31 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:17:39 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t ft_strlen(const char *s);

int	main(int ac, char **av)
{
	const char *s = av[1];
	(void)ac;
	printf("strlen: %ld\nft_strlen: %ld", strlen(s), ft_strlen(s));
	return (0);
}

