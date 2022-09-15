/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:13:35 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:16:46 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);

int	main(int ac, char **av)
{
	(void)ac;
	printf("ft_strchr:\t%s\nstrchr:\t\t%s\n", ft_strchr(av[1], '\0'), strchr(av[1], '\0'));
	printf("\nft_strrchr:\t%s\nstrrchr:\t%s\n", ft_strrchr(av[1], '\0'), strrchr(av[1], '\0'));
	return (0);
}
