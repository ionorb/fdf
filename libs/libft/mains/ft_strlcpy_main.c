/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:18:00 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:17:36 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int	main(int ac, char **av)
{
	size_t		size = atoi(av[3]);
	char		*dst = av[1];
//	char		*dst2 = av[1]
	const char	*src = av[2];

	(void)ac;
//	printf("strlcpy:\nlength: %ld, dst: %s\n", strlcpy(dst1, src, size), dst1);
	printf("ft_strlcpy:\nlength: %ld, dst: %s\n", ft_strlcpy(dst, src, size), dst);
	return (0);
}
