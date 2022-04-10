/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:22:07 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 12:22:08 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
	{
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_clean(char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	if (s1[i] == '\0')
	{
		free (s1);
		return (NULL);
	}
	str = malloc(ft_strlen(s1) - i + 1);
	i++;
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*str;

	if (ft_strlen(s1) <= 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	str = malloc(i + 2);
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\n' && s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = s1[j];
	j++;
	str[j] = '\0';
	return (str);
}
