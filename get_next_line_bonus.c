/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 21:59:02 by hwon              #+#    #+#             */
/*   Updated: 2021/05/17 15:36:24 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*buf_join(char *dst, const char *buf, ssize_t size)
{
	char	*dup;
	char	*anchor;
	size_t	dst_len;
	size_t	index;

	if (!dst)
		dst = ft_strdup("");
	if (size <= 0)
		return (dst);
	dst_len = ft_strlen(dst);
	dup = malloc(dst_len + size + 1);
	if (!dup)
		return (0);
	index = 0;
	while (index < dst_len)
		dup[index++] = *dst++;
	anchor = &(dup[index]);
	index = 0;
	while (index < (size_t)size)
		anchor[index++] = *buf++;
	anchor[index] = 0;
	dst -= dst_len;
	free(dst);
	return (dup);
}

static int	rt_array_free(char **mem, int rt)
{
	free(*mem);
	*mem = 0;
	return (rt);
}

static int	get_line(char **src, char **line)
{
	size_t	len;
	char	*end;
	char	*dup;

	end = ft_strchr(*src, '\n');
	if (end == 0)
	{
		*line = ft_strndup(*src, ft_strlen(*src));
		rt_array_free(src, 0);
		return (0);
	}
	len = (end - *src);
	*line = ft_strndup(*src, len);
	dup = ft_strndup(end + 1, ft_strlen(*src) - (len + 1));
	if (!dup)
		rt_array_free(line, 0);
	rt_array_free(src, 0);
	*src = dup;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*left[INT_MAX];
	ssize_t		read_size;
	size_t		rst;

	buf = malloc(BUFFER_SIZE);
	if (fd >= 0 && !left[fd])
		left[fd] = ft_strdup("");
	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0 || buf == 0 || left[fd] == 0)
		return (rt_array_free(&buf, -1) + rt_array_free(&left[fd], 0));
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		left[fd] = buf_join(left[fd], buf, read_size);
		if (read_size <= 0 || left[fd] == 0 || ft_strchr(left[fd], '\n'))
			break ;
	}
	rt_array_free(&buf, 0);
	if (read_size < 0 || left[fd] == 0)
		return (rt_array_free(&left[fd], -1));
	rst = get_line(&left[fd], line);
	if (*line == 0)
		return (rt_array_free(&left[fd], -1));
	return (rst);
}
