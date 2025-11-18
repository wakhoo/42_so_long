/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:52:02 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/13 11:52:53 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line_bonus.h"

char	*get_read(int fd, char *backup)
{
	char	*buf;
	int		check;

	buf = gnl_ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	if (!backup)
	{
		backup = gnl_ft_calloc(1, 1);
		if (!backup)
			return (NULL);
	}
	check = 1;
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (free_null(buf), free_null(backup), NULL);
		buf[check] = '\0';
		backup = gnl_ft_strjoin(backup, buf);
		if (backup == NULL && gnl_ft_strrchr(backup, '\n'))
			break ;
	}
	return (free_null(buf), backup);
}

char	*get_one(char *backup)
{
	int		i;
	char	*res;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\n')
		res = gnl_ft_calloc(i + 2, 1);
	else
		res = gnl_ft_calloc(i + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		res[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		res[i] = backup[i];
	return (res);
}

char	*set_next(char *backup)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0')
		return (free_null(backup), NULL);
	temp = gnl_ft_calloc(gnl_ft_strlen(backup) - i, 1);
	if (!temp)
		return (free_null(temp), NULL);
	i++;
	j = 0;
	while (backup[i] != '\0')
		temp[j++] = backup[i++];
	return (free_null(backup), temp);
}

char	*clear_gnl(char *backup[1024])
{
	int	cursor;

	cursor = 0;
	while (cursor < 1024)
		free(backup[cursor++]);
	return (NULL);
}

char	*get_next_line(int fd, int mode)
{
	static char	*backup[1024];
	char		*oneline;

	if (mode == CLEAR)
		return (clear_gnl(backup));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	backup[fd] = get_read(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	oneline = get_one(backup[fd]);
	if (!oneline)
		return (NULL);
	backup[fd] = set_next(backup[fd]);
	if (backup[fd] == (char *) 8)
	{
		backup[fd] = NULL;
		free(oneline);
		return (NULL);
	}
	return (oneline);
}
