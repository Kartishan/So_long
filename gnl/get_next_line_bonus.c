/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:20:54 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 13:20:55 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*prev(char *pread, char *buf)
{
	char	*tmp;

	tmp = NULL;
	if (pread == NULL)
	{
		pread = malloc(1);
		pread[0] = '\0';
	}
	tmp = ft_strjoin(pread, buf);
	free(pread);
	pread = tmp;
	return (pread);
}

int	buf_check(char *buf, int red)
{
	if (red == -1)
	{
		free (buf);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*pread[255];
	char		*buf;
	char		*str;
	int			red;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	red = 1;
	while (red > 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (buf_check(buf, red) == 0)
			return (NULL);
		buf[red] = '\0';
		pread[fd] = prev(pread[fd], buf);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	free (buf);
	str = ft_strdup(pread[fd]);
	pread[fd] = ft_clean(pread[fd]);
	return (str);
}
