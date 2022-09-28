/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:40:31 by yridgway          #+#    #+#             */
/*   Updated: 2022/09/28 14:46:46 by yridgway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int	ft_hasnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cutcopy(char *line, char *save)
{
	int		i;
	char	*new;

	i = 0;
	while (save && save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	new = ft_strdup(save + i);
	free(save);
	return (new);
}

char	*ft_makeline(char *save, int *i)
{
	char	*new;
	int		beg;

	beg = *i;
	printf("start:%d\n", *i);
	while (save && save[*i] != '\n' && save[*i])
		(*i)++;
	if (save[*i] == '\n')
		(*i)++;
	new = (char *)malloc((*i + 1) * sizeof (char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, save + beg, *i + 1);
	printf("start:%d\n", *i);
	return (new);
}

char	*get_next_line(int fd, int *start)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*save;
	char			*line;
	int				i;

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && !ft_hasnl(save))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		buf[i] = '\0';
		save = ft_strjoin(save, buf);
	}
	if (i < BUFFER_SIZE && *start >= (int)ft_strlen(save) - 1)
	{
			free(save);
			return (NULL);
	}
	line = ft_makeline(save, start);
	printf("line:%s\n", line);
	return (line);
}*/


int	ft_hasnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cutcopy(char *line, char *save)
{
	int		i;
	char	*new;

	i = 0;
	while (save && save[i] != '\n' && save[i])
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	new = ft_strdup(save + i);
	free(save);
	return (new);
}

char	*ft_makeline(char *save)
{
	int		i;
	char	*new;

	i = 0;
	while (save && save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n')
		i++;
	new = (char *)malloc((i + 1) * sizeof (char));
	if (!new)
		return (NULL);
	return (new);
}

char	*get_next_line(int fd, int a)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*save;
	char			*line;
	int				i;

	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE && !ft_hasnl(save))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		buf[i] = '\0';
		save = ft_strjoin(save, buf);
	}
	if (!save || (i < BUFFER_SIZE && !save[0]))
	{
			if (a)
				free(save);
			return (NULL);
	}
	line = ft_makeline(save);
	save = ft_cutcopy(line, save);
	return (line);
}
/*
-----------------------------------------------------------------------

static char	*function_name(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = function_name(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}*/
