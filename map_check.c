/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:17:25 by pwildcat          #+#    #+#             */
/*   Updated: 2022/03/06 18:17:27 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	all_check(char **line)
{
	int	i;
	int	j;

	if (arg_check(line, 0, 0, 0) == 1)
		return (1);
	i = 1;
	while (line[i] != NULL)
	{
		j = 0;
		if (line[i + 1] == NULL)
		{
			if (arg_check(line, i, j, 1) == 1)
				return (1);
		}
		while (line[i][j] != '\n')
		{
			if (arg_check(line, i, j, 2) == 1)
				return (1);
			j++;
		}
		i++;
	}
	if (check_length(line) == 1 || check_min(line, 0, 0) == 1)
		return (1);
	return (0);
}

void	map_inic(t_mapMV *mp, char **line)
{
	mp->mlx = mlx_init();
	mp->window = mlx_new_window(mp->mlx, 1080, 1024, "so_long");
	mp->h = 32;
	mp->go = 0;
	mp->imgback = mlx_png_file_to_image(mp->mlx, "Blue.png", &mp->h, &mp->h);
	mp->imgs = mlx_png_file_to_image(mp->mlx, "Idles.png", &mp->h, &mp->h);
	mp->img = mlx_png_file_to_image(mp->mlx, "AG.png", &mp->h, &mp->h);
	mp->imge = mlx_png_file_to_image(mp->mlx, "End.png", &mp->h, &mp->h);
	mp->imgc = mlx_png_file_to_image(mp->mlx, "Apple.png", &mp->h, &mp->h);
}

int	map_picture(char **line, t_mapMV *mp)
{
	mp->i = 0;
	while (line[mp->i] != NULL)
	{
		mp->j = 0;
		while (line[mp->i][mp->j] != '\n')
		{
			if (line[mp->i][mp->j] == '1')
				image_to(mp, mp->imgs, mp->i, mp->j);
			else if (line[mp->i][mp->j] == '0' || line[mp->i][mp->j] == 'P')
				image_to(mp, mp->imgback, mp->i, mp->j);
			else if (line[mp->i][mp->j] == 'E')
				image_to(mp, mp->imge, mp->i, mp->j);
			else if (line[mp->i][mp->j] == 'C')
				image_to(mp, mp->imgc, mp->i, mp->j);
			mp->j++;
		}
		mp->i++;
	}
	return (0);
}

int	all_actions(char **line, t_mapMV *mp)
{
	int	h;

	h = 32;
	mlx_key_hook(mp->window, run, mp);
	mlx_hook(mp->window, 17, 0, full_clear, mp);
	return (0);
}
