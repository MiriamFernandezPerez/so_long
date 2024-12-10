/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:48:49 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/31 23:37:14 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->w * map->h)
	{
		if (map->tile[i].y == 0 || map->tile[i].y == map->h - 1
			|| map->tile[i].x == 0 || map->tile[i].x == map->w - 1)
		{
			if (map->tile[i].val != '1')
				ft_error(WALL_ERR);
		}
		i++;
	}
}

void	check_player(int player)
{
	if (player != 1)
	{
		if (player == 0)
			ft_error(NO_PLAYER);
		else
			ft_error(TOO_PLAYERS);
	}
}

void	check_items(int items)
{
	if (items == 0)
		ft_error(NO_COLLECTS);
}

void	check_exit(int exit)
{
	if (exit != 1)
	{
		if (exit == 0)
			ft_error(NO_EXIT);
		else
			ft_error(TOO_EXITS);
	}
}

void	check_char_item(t_map *map, char c, int i)
{
	if (c == 'P')
	{
		map->player.val = 'P';
		map->player.qt++;
		map->player.x = map->tile[i].x;
		map->player.y = map->tile[i].y;
	}
	else if (c == 'C')
	{
		map->items.val = 'C';
		map->items.qt += 1;
		map->items.x = map->tile[i].x;
		map->items.y = map->tile[i].y;
		map->collect += 1;
	}
	else if (c == 'E')
	{
		map->exit.val = 'E';
		map->exit.qt++;
		map->exit.x = map->tile[i].x;
		map->exit.y = map->tile[i].y;
	}
}
