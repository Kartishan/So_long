/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:05:45 by pwildcat          #+#    #+#             */
/*   Updated: 2022/03/26 16:05:47 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	image_to(t_mapMV *mp, void	*name, int i, int j)
{
	mlx_put_image_to_window(mp->mlx, mp->window, name, j * 32, i * 32);
}

void	player_search(char **line, t_mapMV *mp)
{
	int	flag;

	flag = 0;
	mp->i = 1;
	mp->c = 0;
	while (line[mp->i] != NULL)
	{
		mp->j = 0;
		while (line[mp->i][mp->j] != '\n')
		{
			if (line[mp->i][mp->j] == 'P' && flag == 1)
				line[mp->i][mp->j] = '0';
			else if (line[mp->i][mp->j] == 'P' && flag == 0)
			{
				mp->x = mp->j;
				mp->y = mp->i;
				image_to(mp, mp->img, mp->i, mp->j);
				flag = 1;
			}
			else if (line[mp->i][mp->j] == 'C')
				mp->c++;
			mp->j++;
		}
		mp->i++;
	}
}

void	ft_putnbr(int n)
{
	long int	t;
	long int	nb;
	char		c;
	long int	nan;

	nan = n;
	if (nan < 0)
	{
		nan = nan * -1;
		write(1, "-", 1);
	}
	nb = 1;
	t = nan;
	while (t > 9)
	{
		nb *= 10;
		t /= 10;
	}
	while (nb != 0)
	{
		t = nan / nb % 10;
		c = t + '0';
		write(1, &c, 1);
		nb /= 10;
	}
}
