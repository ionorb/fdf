/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:33:04 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:12:52 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n);

int	main(int ac, char **av)
{
	char	*ogresult = memchr(av[1], av[2][0], atoi(av[3]));
	char	*myresult = ft_memchr(av[1], av[2][0], atoi(av[3]));
//	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	
	(void)ac;
	printf("memchr:\t\t%s\nft_memchr\t%s\n", ogresult, myresult);
//	printf("%s", (char *)ft_memchr(tab, -1, 7));
	return (0);
}
