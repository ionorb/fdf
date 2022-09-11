/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:40:42 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/11 21:08:58 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	int	height;
	int	width;
	int	**matrix;
}	t_data;

char	*get_next_line(int fd);
void	read_file(char *filename, t_data *data);
char	**ft_split(char *s, char *str);
int		ft_atoi(const char *nptr);
int		ft_hasnl(char	*str);
char	*ft_strjoin(char *s1, char *s2);
#endif
