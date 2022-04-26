/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:37:23 by pwildcat          #+#    #+#             */
/*   Updated: 2022/04/15 18:37:38 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	ft_countmemory(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;

	j = 0;
	i = 0;
	if (ft_strlen(s) >= start)
	{
		while (i < start)
			i++;
		while (j < len && s[i] != '\0')
		{
			j++;
			i++;
		}
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*p;

	j = 0;
	if (!s)
		return (NULL);
	p = malloc(sizeof(char) * (ft_countmemory(s, start, len) + 1));
	if (p == NULL)
		return ((void *)0);
	i = 0;
	if (ft_strlen(s) >= start)
	{
		while (i < start)
			i++;
		while (j < len && s[i] != '\0')
		{
			p[j] = s[i];
			j++;
			i++;
		}
	}
	p[j] = '\0';
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1 && (*p != '\0') && (*q != '\0') && *p == *q)
	{
		p++;
		q++;
		n--;
	}
	return (*p - *q);
}
