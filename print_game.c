/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:45:58 by mirifern          #+#    #+#             */
/*   Updated: 2024/06/17 22:08:48 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_floor(t_vars *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->data->w)
	{
		y = 0;
		while (y < game->data->h)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->ffile[0],
				(game->w * x), (game->h * y));
			y++;
		}
		x++;
	}
}

void	print_item(t_vars *g, int x, int y, char c)
{
	int	i;

	i = 0;
	if (c == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->wfile[i],
			(g->w * x), (g->h * y));
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->dfile[0],
			(g->w * x), (g->h * y));
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->tfile[i],
			(g->w * x), (g->h * y));
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->sfile[i],
			(g->w * x), (g->h * y));
	}
}

void	check_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error (NO_SPRITE);
}

void	init_sprites(t_vars *g)
{
	g->ffile = malloc(sizeof(char *) * 1);
	g->wfile = malloc(sizeof(char *) * 1);
	g->dfile = malloc(sizeof(char *) * 1);
	g->tfile = malloc(sizeof(char *) * 1);
	g->sfile = malloc(sizeof(char *) * 1);
	if (!g->ffile || !g->wfile || !g->dfile || !g->tfile || !g->sfile)
		ft_error(MALLOC_ERR);
	check_open(FLOOR);
	check_open(WALL);
	check_open(DIAMOND1);
	check_open(TRAPDOOR);
	check_open(STEVE1);
	g->ffile[0] = mlx_xpm_file_to_image(g->mlx, FLOOR, &g->w, &g->h);
	g->wfile[0] = mlx_xpm_file_to_image(g->mlx, WALL, &g->w, &g->h);
	g->dfile[0] = mlx_xpm_file_to_image(g->mlx, DIAMOND1, &g->w, &g->h);
	g->tfile[0] = mlx_xpm_file_to_image(g->mlx, TRAPDOOR, &g->w, &g->h);
	g->sfile[0] = mlx_xpm_file_to_image(g->mlx, STEVE1, &g->w, &g->h);
}

void	print_game(t_vars *game)
{
	int	x;
	int	y;

	y = 0;
	print_floor(game);
	while (y < game->data->h)
	{
		x = 0;
		while (x < game->data->w)
		{
			if (game->map[y][x] == '1')
				print_item(game, x, y, '1');
			else if (game->map[y][x] == 'C')
				print_item(game, x, y, 'C');
			else if (game->map[y][x] == 'P')
				print_item(game, x, y, 'P');
			else if (game->map[y][x] == 'E')
				print_item(game, x, y, 'E');
			x++;
		}
		y++;
	}
}
