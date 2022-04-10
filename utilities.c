/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:21:23 by pwildcat          #+#    #+#             */
/*   Updated: 2022/03/18 17:21:24 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	colvo(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		i++;
	return (i);
}

void	map_free(char **line)
{
	int	i;

	if (line == NULL)
		return ;
	i = 0;
	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
	}
	free(line[i]);
	free(line);
}

void	tmp_return(char **tmp, char **line, int j)
{
	int		i;
	char	*s;

	i = 0;
	while (i < j)
	{
		s = tmp[i];
		line[i] = s;
		i++;
	}
	free (tmp);
}

int	check_first_or_last(char **line, int i, int flag)
{
	int	j;

	j = 0;
	if (flag == 0 || flag == 1)
	{
		while (line[i][j] != '\n')
		{
			if (line[i][j] != '1')
				return (1);
			j++;
		}
	}
	return (0);
}

int	full_clear(t_mapMV *mp)
{
	mlx_destroy_image(mp->mlx, mp->img);
	mlx_destroy_image(mp->mlx, mp->imgback);
	mlx_destroy_image(mp->mlx, mp->imgc);
	mlx_destroy_image(mp->mlx, mp->imge);
	mlx_destroy_image(mp->mlx, mp->imgs);
	mlx_destroy_window(mp->mlx, mp->window);
	map_free(mp->line);
	exit(0);
}
