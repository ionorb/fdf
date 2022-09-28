/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:46:28 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/28 14:47:06 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char	*filename, t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		free(data);
		exit(0);
	}
	i = 0;
	line = get_next_line(fd, 0);
	while (line && line[0])
	{
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

int	get_width(char	*filename)
{
	int		i;
	int		fd;
	char	*line;
	char	**numbers;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd, 0);
	numbers = ft_split(line, " \n");
	free(line);
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	line = get_next_line(fd, 0);
	while (line && line[0])
	{
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
	free(numbers);
	return (i);
}

void	fill_matrix(int *arr, char *line)
{
	int		i;
	char	**numbers;

	i = 0;
	numbers = ft_split(line, " ");
	while (numbers[i])
	{
		arr[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
}	

void	read_file(char *filename, t_data *data)
{
	char	*line;
	int		i;
	int		fd;

	data->height = get_height(filename, data);
	data->width = get_width(filename);
	i = -1;
	data->matrix = malloc((data->height + 1) * sizeof (int *));
	while (++i < data->height)
		data->matrix[i] = malloc((data->width + 1) * sizeof (int));
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (i <= data->height)
	{
		line = get_next_line(fd, 1);
		if (line)
				fill_matrix(data->matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
}
