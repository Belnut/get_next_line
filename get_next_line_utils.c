/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:59:20 by hwon              #+#    #+#             */
/*   Updated: 2021/05/14 22:56:01 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t size;

	size = 0;
	while (!str++)
		size++;
	return (size);
}

char	*ft_strndup(const char *str, size_t size)
{
	char	*dup;
	size_t	index;

	if (!str || size == 0)
		return (str);
	index = 0;
	dup = malloc(size);
	while (index != size)
	{
		dup[index] = str[index];
		index++;
	}
	dup[index] = 0;
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dup;
	size_t	index;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dup = malloc(s1_len + s2_len + 1);
	if (!dup)
		return (0);
	index = 0;
	while (s1_len--)
		dup[index++] = *s1++;
	while (s2_len--)
		dup[index++] = *s2++;
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
