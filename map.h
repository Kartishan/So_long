/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:27:35 by pwildcat          #+#    #+#             */
/*   Updated: 2022/03/18 17:27:38 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <unistd.h>
# include <stdio.h>
# include "./gnl/get_next_line_bonus.h"
# include "./minilibx_mms_20200219/mlx.h"
# include <fcntl.h>

typedef struct s_mapMoves
{
	int		x;
	int		y;
	int		h;

	void	*img;
	void	*mlx;
	void	*window;
	void	*imgback;
	void	*imgs;
	void	*imge;
	void	*imgc;
	char	**line;
	int		i;
	int		j;
	int		c;
	int		go;
}	t_mapMV;

typedef struct s_pplayer
{
	int		x;
	int		y;
	int		i;
	int		j;
}	t_pplayer;

void	map_free(char **line);
void	tmp_return(char **tmp, char **line, int j);
int		check_first_or_last(char **line, int i, int flag);
char	**map_fill(int fd);
int		arg_check(char **line, int i, int j, int flag);
int		check_length(char **line);
int		check_min(char **line, int i, int j);
int		run(int key, void *param);
int		map_picture(char **line, t_mapMV *mp);
int		all_actions(char **line, t_mapMV *mp);
int		all_check(char **line);
void	player_search(char **line, t_mapMV *mp);
void	move_right(char **line, t_mapMV *mp);
void	move_left(char **line, t_mapMV *mp);
void	move_up(char **line, t_mapMV *mp);
void	move_down(char **line, t_mapMV *mp);
void	map_inic(t_mapMV *mp, char **line);
void	image_to(t_mapMV *mp, void	*name, int i, int j);
int		full_clear(t_mapMV *mp);
void	ft_putnbr(int n);
int		max_in_line(t_mapMV *mp);
int		max_in_s(t_mapMV *mp);
void	paint_sprite(t_mapMV *mp, t_pplayer *pp);
void	player_to_cent(t_mapMV *mp);
int		x_min(t_mapMV *mp);
int		y_min(t_mapMV *mp);
int		x_max(t_mapMV *mp);
int		y_max(t_mapMV *mp);
int		ft_countmemory(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	v_checker(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
