/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:18:55 by pwildcat          #+#    #+#             */
/*   Updated: 2022/03/26 15:18:57 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	**map_fill(int fd)
{
	char	**tmp;
	char	**line;
	char	*s;
	int		i;

	i = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		line = (char **)malloc(sizeof(char *) * (i + 2));
		if (line == NULL)
		{
			map_free(line);
			exit (0);
		}
		line[i] = s;
		line[i + 1] = NULL;
		if (i > 0)
			tmp_return(tmp, line, i);
		tmp = line;
		i++;
	}
	return (line);
}

int	arg_check(char **line, int i, int j, int flag)
{
	if (flag == 0 || flag == 1)
	{
		return (check_first_or_last(line, i, flag));
	}
	if (line[i][j] != '0' && line[i][j] != '1' && line[i][j] != 'P'
			&& line[i][j] != 'C' && line[i][j] != 'E')
	{
		return (1);
	}
	if (line[i][j + 1] == '\n')
	{
		if (line[i][j] != '1')
			return (1);
	}
	if (j == 0)
	{
		if (line[i][j] != '1')
			return (1);
	}
	return (0);
}

int	check_length(char **line)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	j = 0;
	while (line[0][j] != '\n')
		j++;
	m = j - 1;
	i = 1;
	while (line[i] != NULL)
	{
		j = 0;
		while (line[i][j] != '\n')
			j++;
		if (--j != m)
			return (1);
		i++;
	}
	return (0);
}

int	check_min(char **line, int i, int j)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	while (line[i] != NULL)
	{
		j = 0;
		while (line[i][j] != '\n')
		{
			if (line[i][j] == 'P')
				p++;
			if (line[i][j] == 'C')
				c++;
			if (line[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p == 0 || c == 0 || e == 0)
		return (1);
	return (0);
}

int	run(int key, void *param)
{
	t_mapMV	*mp;

	mp = (t_mapMV *)param;
	if (key == 53)
		full_clear(mp);
	else if (key == 2)
		move_right(mp->line, mp);
	else if (key == 0)
		move_left(mp->line, mp);
	else if (key == 13)
		move_up(mp->line, mp);
	else if (key == 1)
		move_down(mp->line, mp);
	else
		return (0);
	ft_putnbr(mp->go);
	write(1, "\n", 1);
	player_to_cent(mp);
	return (0);
}
