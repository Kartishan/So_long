/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:33:53 by pwildcat          #+#    #+#             */
/*   Updated: 2022/03/26 15:33:58 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	move_right(char **line, t_mapMV *mp)
{
	if (line[mp->y][mp->x + 1] != '1' && line[mp->y][mp->x + 1] != '\n')
	{
		if (line[mp->y][mp->x + 1] == 'C')
		{
			line[mp->y][mp->x + 1] = '0';
			mp->c--;
		}
		if (line[mp->y][mp->x + 1] == '0' ||
			(line[mp->y][mp->x + 1] == 'E' && mp->c == 0))
		{
			if (line[mp->y][mp->x + 1] == 'E' && mp->c == 0)
				full_clear(mp);
			line[mp->y][mp->x] = '0';
			mp->x = mp->x + 1;
			line[mp->y][mp->x] = 'P';
			mp->go++;
		}
	}
}

void	move_left(char **line, t_mapMV *mp)
{
	if (line[mp->y][mp->x - 1] != '1' && line[mp->y][mp->x - 1] != '\n')
	{
		if (line[mp->y][mp->x - 1] == 'C')
		{
			line[mp->y][mp->x - 1] = '0';
			mp->c--;
		}
		if (line[mp->y][mp->x - 1] == '0' ||
			(line[mp->y][mp->x - 1] == 'E' && mp->c == 0))
		{
			if (line[mp->y][mp->x - 1] == 'E' && mp->c == 0)
				full_clear(mp);
			line[mp->y][mp->x] = '0';
			mp->x = mp->x - 1;
			line[mp->y][mp->x] = 'P';
			mp->go++;
		}
	}
}

void	move_up(char **line, t_mapMV *mp)
{
	if (line[mp->y - 1][mp->x] != '1' && line[mp->y - 1][mp->x] != '\n')
	{
		if (line[mp->y - 1][mp->x] == 'C')
		{
			line[mp->y - 1][mp->x] = '0';
			mp->c--;
		}
		if (line[mp->y - 1][mp->x] == '0' ||
			(line[mp->y - 1][mp->x] == 'E' && mp->c == 0))
		{
			if (line[mp->y - 1][mp->x] == 'E')
				full_clear(mp);
			line[mp->y][mp->x] = '0';
			mp->y = mp->y - 1;
			line[mp->y][mp->x] = 'P';
			mp->go++;
		}
	}
}

void	move_down(char **line, t_mapMV *mp)
{
	if (line[mp->y + 1][mp->x] != '1' && line[mp->y + 1][mp->x] != '\n')
	{
		if (line[mp->y + 1][mp->x] == 'C')
		{
			line[mp->y +1][mp->x] = '0';
			mp->c--;
		}
		if (line[mp->y + 1][mp->x] == '0' ||
			(line[mp->y + 1][mp->x] == 'E' && mp->c == 0))
		{
			if (line[mp->y + 1][mp->x] == 'E')
				full_clear(mp);
			line[mp->y][mp->x] = '0';
			mp->y = mp->y + 1;
			line[mp->y][mp->x] = 'P';
			mp->go++;
		}
	}
}
