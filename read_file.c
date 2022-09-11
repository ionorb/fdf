/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaccount <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 00:46:28 by myaccount         #+#    #+#             */
/*   Updated: 2022/09/11 17:50:32 by myaccount        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char	*filename)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

int		get_width(char	*filename)
{
	int		i;
	int		fd;
	char	*line;
	char	**numbers;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	numbers = ft_split(line, " \n");
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	free(numbers);
	free(line);
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

	data->height = get_height(filename);
	data->width = get_width(filename);
	i = -1;
	data->matrix = malloc((data->height + 1) * sizeof (int*));
	while (++i < data->height)
		data->matrix[i] = malloc((data->width + 1) * sizeof (int));
	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->matrix[i], line);
		free(line);
		i++;
	}
	data->matrix[i] = NULL;
	close(fd);
}
