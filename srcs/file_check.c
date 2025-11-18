/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:59:37 by chajeon           #+#    #+#             */
/*   Updated: 2024/04/19 21:35:29 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_strnstr_i(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	if (*needle == '\0')
		return (ft_strlen(haystack));
	while (i < len && haystack[i])
	{
		n = i;
		j = 0;
		while (haystack[n] == needle[j] && haystack[n] && needle[j] && n < len)
		{
			n++;
			j++;
		}
		if (needle[j] == '\0')
			return (i);
		i++;
	}
	return (0);
}

int	ft_file_check(char	*filename)
{
	int	check;
	int	len;

	len = ft_strlen(filename);
	check = ft_strnstr_i(filename, ".ber", len);
	if ((len - check) == 4)
		return (1);
	return (0);
}
