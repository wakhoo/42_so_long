/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:35:47 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/11 15:15:30 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/get_next_line_bonus.h"

void	*gnl_ft_calloc(size_t count, size_t size)
{
	size_t			i;
	size_t			max_int;
	unsigned char	*str;

	max_int = 2147483647;
	if (count * size > max_int || count > max_int || size > max_int)
		return (NULL);
	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < count * size)
		str[i++] = (unsigned char) '\0';
	return ((void *)str);
}

void	free_null(char *str)
{
	free(str);
}

int	gnl_ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *str, char *add)
{
	int		i;
	int		j;
	int		total;
	char	*join;

	if (!str || !add)
		return (NULL);
	total = gnl_ft_strlen(str) + gnl_ft_strlen(add);
	join = gnl_ft_calloc(total + 1, 1);
	if (!join)
		return (NULL);
	i = 0;
	while (str[i])
	{
		join[i] = str[i];
		i++;
	}
	j = 0;
	while (add[j])
	{
		join[i + j] = add[j];
		j++;
	}
	return (free_null(str), join);
}

char	*gnl_ft_strrchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = gnl_ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
