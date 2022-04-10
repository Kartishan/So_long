/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:21:57 by pwildcat          #+#    #+#             */
/*   Updated: 2021/12/08 12:21:59 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*prev(char *pread, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_clean(char *pread);
size_t	ft_strlen(const char *c);
int		buf_check(char *buf, int red);

#endif
