/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:20:10 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 13:20:24 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*prev(char *pread, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_clean(char *pread);
size_t	ft_strlen(const char *c);
int		buf_check(char *buf, int red);

#endif
