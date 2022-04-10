/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:49:17 by pwildcat          #+#    #+#             */
/*   Updated: 2022/03/26 15:49:19 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_mapMV	mp;

	if (argc != 2)
	{
		write(1, "Вы забыли ввести карту\n", 42);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	mp.line = map_fill(fd);
	if (all_check(mp.line) == 1)
	{
		write(1, "Карта не валидна\n", 33);
		exit(0);
	}
	map_inic(&mp, mp.line);
	map_picture(mp.line, &mp);
	player_search(mp.line, &mp);
	all_actions(mp.line, &mp);
	mlx_loop(mp.mlx);
	return (0);
}
