/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:19:20 by pwildcat          #+#    #+#             */
/*   Updated: 2022/04/15 18:19:27 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	x_min(t_mapMV *mp)
{
	int	i;
	int	x;

	i = 0;
	x = mp->x;
	while (x > 0 && i != 16)
	{
		x--;
		i++;
	}
	return (x);
}

int	y_min(t_mapMV *mp)
{
	int	i;
	int	x;

	i = 0;
	x = mp->y;
	while (x > 0 && i != 16)
	{
		x--;
		i++;
	}
	return (x);
}

int	x_max(t_mapMV *mp)
{
	int	x;
	int	i;

	i = 0;
	x = mp->x;
	while (x != max_in_s(mp) && i != 16)
	{
		x++;
		i++;
	}
	return (x--);
}

int	y_max(t_mapMV *mp)
{
	int	x;
	int	i;

	i = 0;
	x = mp->y;
	while (x != max_in_line(mp) && i != 16)
	{
		x++;
		i++;
	}
	return (x--);
}
