/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:50:06 by mirifern          #+#    #+#             */
/*   Updated: 2024/06/02 03:58:09 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_vars *game)
{
	int	x;
	int	y;

	x = game->data->player.x;
	y = game->data->player.y;
	game->map[y][x] = '0';
	if (game->exit == 1)
	{
		game->map[y][x] = 'E';
		game->exit = 0;
	}
	if (game->map[y - 1][x] == 'E')
		game->exit = 1;
	if (game->map[y - 1][x] == 'C')
		game->data->items.qt--;
	game->map[y - 1][x] = 'P';
	game->data->player.y--;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" moves\n", 1);
}

void	ft_down(t_vars *game)
{
	int	x;
	int	y;

	x = game->data->player.x;
	y = game->data->player.y;
	game->map[y][x] = '0';
	if (game->exit == 1)
	{
		game->map[y][x] = 'E';
		game->exit = 0;
	}
	if (game->map[y + 1][x] == 'E')
		game->exit = 1;
	if (game->map[y + 1][x] == 'C')
		game->data->items.qt--;
	game->map[y + 1][x] = 'P';
	game->data->player.y++;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" moves\n", 1);
}

void	ft_left(t_vars *game)
{
	int	x;
	int	y;

	x = game->data->player.x;
	y = game->data->player.y;
	game->map[y][x] = '0';
	if (game->exit == 1)
	{
		game->map[y][x] = 'E';
		game->exit = 0;
	}
	if (game->map[y][x - 1] == 'E')
		game->exit = 1;
	if (game->map[y][x - 1] == 'C')
		game->data->items.qt--;
	game->map[y][x - 1] = 'P';
	game->data->player.x--;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" moves\n", 1);
}

void	ft_right(t_vars *game)
{
	int	x;
	int	y;

	x = game->data->player.x;
	y = game->data->player.y;
	game->map[y][x] = '0';
	if (game->exit == 1)
	{
		game->map[y][x] = 'E';
		game->exit = 0;
	}
	if (game->map[y][x + 1] == 'E')
		game->exit = 1;
	if (game->map[y][x + 1] == 'C')
		game->data->items.qt--;
	game->map[y][x + 1] = 'P';
	game->data->player.x++;
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" moves\n", 1);
}
