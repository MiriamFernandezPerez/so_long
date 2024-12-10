/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:25:49 by mirifern          #+#    #+#             */
/*   Updated: 2024/06/17 22:18:31 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# include "../mlx_linux/mlx.h"

int	close_window(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	move_to_e(t_vars *game, int c)
{
	if (c == UP)
		ft_up(game);
	if (c == DOWN)
		ft_down(game);
	if (c == LEFT)
		ft_left(game);
	if (c == RIGHT)
		ft_right(game);
	game->map[game->data->player.y][game->data->player.x] = 'E';
	print_game(game);
	print_item(game, game->data->player.x, game->data->player.y, 'P');
}

int	moves(int c, t_vars *g)
{
	int	x;
	int	y;

	x = g->data->player.x;
	y = g->data->player.y;
	if (c == ESC)
		close_window(g);
	if (g->data->items.qt == 0 && ((c == UP && g->map[y - 1][x] == 'E')
		|| (c == DOWN && g->map[y + 1][x] == 'E')
		|| (c == LEFT && g->map[y][x - 1] == 'E')
		|| (c == RIGHT && g->map[y][x + 1] == 'E')))
	{
		move_to_e(g, c);
		return (0);
	}
	else if (c == UP && g->map[y - 1][x] != '1')
		ft_up(g);
	else if (c == DOWN && g->map[y + 1][x] != '1')
		ft_down(g);
	else if (c == LEFT && g->map[y][x - 1] != '1')
		ft_left(g);
	else if (c == RIGHT && g->map[y][x + 1] != '1')
		ft_right(g);
	print_game(g);
	return (0);
}

void	create_map(t_vars *game, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	game->map = (char **)malloc(map->h * sizeof(char *));
	if (!game->map)
		ft_error(MALLOC_ERR);
	while (i < map->h)
	{
		j = 0;
		(game->map)[i] = (char *)malloc((map->w + 1) * sizeof(char));
		if (!(game->map)[i])
			ft_error(MALLOC_ERR);
		while (j < map->w)
		{
			game->map[i][j] = map->tile[i * map->w + j].val;
			j++;
		}
		game->map[i][j] = '\0';
		i++;
	}
}

int	init_game(t_map *map)
{
	t_vars	*game;

	game = malloc(sizeof(t_vars));
	if (!game)
		ft_error(MALLOC_ERR);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error(MALLOC_ERR);
	game->win = mlx_new_window(game->mlx, (map->w * 80), \
			(map->h * 80), "So_long");
	if (!game->win)
		ft_error(MALLOC_ERR);
	game->data = map;
	game->moves = 0;
	game->exit = 0;
	create_map(game, map);
	init_sprites(game);
	print_game(game);
	mlx_loop_hook(game->mlx, render, game);
	mlx_hook(game->win, 2, 1L << 0, moves, game);
	mlx_hook(game->win, 17, 1L << 5, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
