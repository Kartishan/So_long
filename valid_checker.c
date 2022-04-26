/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:45:54 by pwildcat          #+#    #+#             */
/*   Updated: 2022/04/15 18:45:56 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	v_checker(char *str)
{
	char	*valid;

	valid = ft_substr(str, ft_strlen(str) - 4, 4);
	if (ft_strncmp(valid, ".ber", 4) == 0)
		free (valid);
	else
	{
		free (valid);
		write(1, "Error\n", 6);
		exit (0);
	}
}
