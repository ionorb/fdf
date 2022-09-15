/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:26:15 by yridgway          #+#    #+#             */
/*   Updated: 2022/05/22 14:16:47 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_striteri(char *s, void (*f)(unsigned int, char*));

void	f(unsigned int i, char *str)
{
	str[i] = 'g';
}

int	main(int ac, char **av)
{
	char	*str = av[1];

	(void)ac;
	void (*foo)(unsigned int, char *) = &f;
	ft_striteri(str, foo);
	printf("edit: %s", str);
	return (0);
}
