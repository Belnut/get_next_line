/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwon <ohj8447@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:00:10 by hwon              #+#    #+#             */
/*   Updated: 2021/05/17 15:37:52 by hwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, size_t size);
void	*ft_memset(void *mem, int value, size_t size);
int		get_next_line(int ft, char **line);

#endif
