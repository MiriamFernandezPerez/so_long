/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:36:34 by mirifern          #+#    #+#             */
/*   Updated: 2024/05/29 22:51:16 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(t_map *map)
{
	int		i;

	i = 0;
	while (i < (map->w * map->h))
	{
		if (map->tile[i].val == '1')
			map->spaces++;
		else if (map->tile[i].val == '0')
			map->spaces++;
		else if (map->tile[i].val == 'P' || map->tile[i].val == 'C'
			|| map->tile[i].val == 'E')
			check_char_item(map, map->tile[i].val, i);
		else
			ft_error(INV_MAP_CHAR);
		i++;
	}
	return (0);
}

void	check_map(t_map *map, t_tile *tile)
{
	if (map->w * map->h > 50000)
		ft_error(TOO_BIG);
	map->tile = tile;
	check_chars(map);
	check_player(map->player.qt);
	check_items(map->items.qt);
	check_exit(map->exit.qt);
	check_walls(map);
	check_solution(map);
}

void	fill_tile(char *line, t_tile *tile, int *index, int y)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == '\n')
			break ;
		tile[*index].val = line[i];
		tile[*index].x = i;
		tile[*index].y = y;
		i++;
		(*index)++;
	}
}

void	create_tile(t_map *map, char *path)
{
	t_tile	*tile;
	int		fd;
	char	*line;
	int		index;
	int		i;

	index = 0;
	i = 0;
	tile = malloc(sizeof(t_tile) * (map->w * map->h));
	if (!tile)
		ft_error(MALLOC_ERR);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(NO_FILE);
	line = get_next_line(fd);
	while (line)
	{
		fill_tile(line, tile, &index, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	check_map(map, tile);
	close(fd);
}
