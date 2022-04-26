/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:49:17 by pwildcat          #+#    #+#             */
/*   Updated: 2022/04/15 16:05:10 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	max_in_line(t_mapMV *mp)
{
	int	i;

	i = 0;
	while (mp->line[i] != NULL)
		i++;
	return (i);
}

int	max_in_s(t_mapMV *mp)
{
	int	i;

	i = 0;
	while (mp->line[0][i] != '\n')
		i++;
	return (i);
}

void	player_to_cent(t_mapMV *mp)
{
	t_pplayer	pp;

	pp.y = mp->y - 8;
	pp.i = 0;
	mlx_clear_window(mp->mlx, mp->window);
	while (pp.i < 16)
	{
		pp.x = mp->x - 8;
		pp.j = 0;
		while (pp.j < 16)
		{
			if (pp.x >= 0 && pp.x < max_in_s(mp)
				&& pp.y >= 0 && pp.y < max_in_line(mp))
				paint_sprite(mp, &pp);
			pp.x++;
			pp.j++;
		}
		pp.y++;
		pp.i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_mapMV	mp;

	if (argc != 2)
	{
		write(1, "Вы забыли ввести карту\n", 42);
		return (0);
	}
	v_checker (argv[1]);
	fd = open(argv[1], O_RDONLY);
	mp.line = map_fill(fd);
	if (all_check(mp.line) == 1)
	{
		write(1, "Карта не валидна\n", 33);
		exit(0);
	}
	map_inic(&mp, mp.line);
	player_search(mp.line, &mp);
	player_to_cent(&mp);
	all_actions(mp.line, &mp);
	mlx_loop(mp.mlx);
	return (0);
}
