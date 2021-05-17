/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:59:20 by hwon              #+#    #+#             */
/*   Updated: 2021/05/17 14:48:37 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == (char)c)
			return (char *)(--str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t size;

	size = 0;
	while (*str++)
		size++;
	return (size);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	index;

	if (!str)
		return (char *)(str);
	index = 0;
	dup = malloc(ft_strlen(str) + 1);
	while (str[index])
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = 0;
	return (dup);
}

char	*ft_strndup(const char *str, size_t size)
{
	char	*dup;
	size_t	index;

	if (!str)
		return (char *)(str);
	if (size == 0)
		return (ft_strdup(""));
	index = 0;
	dup = malloc(size + 1);
	while (index != size && str[index])
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = 0;
	return (dup);
}

void	*ft_memset(void *mem, int value, size_t size)
{
	char	*tmp;
	void	*anchor;

	if (!mem || size == 0)
		return (mem);
	anchor = mem;
	tmp = (char *)mem;
	while (size-- != 0)
		*tmp++ = value;
	return (anchor);
}
