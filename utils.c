/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:50:53 by mirifern          #+#    #+#             */
/*   Updated: 2024/06/02 03:05:28 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	(void)s;
	write (1, s, ft_strlen(s));
	exit(1);
}

char	**ft_free(char **ptr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

int	render(t_vars *game)
{
	int	x;
	int	y;

	x = game->data->player.x;
	y = game->data->player.y;
	if (game->data->items.qt == 0 && (game->map[y][x] == 'E'))
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		close_window(game);
	}
	return (0);
}
