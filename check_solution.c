/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:58:51 by mirifern          #+#    #+#             */
/*   Updated: 2024/06/05 21:43:53 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/************ win () *****************
* Check if player can get the exit collecting all the items first
* Check if player is outside the map
* Check if player has been at this place
* Marck the position as visited
* Decrease amount of items every time player get a C collect item
* Move in four directions (up, down, left, right)
* Unmark the position as visited (backtracking)
* Decrease the item count if it had been increased.
* ****************************************************/

int	win(t_map *map, t_item p, t_item items, char **visit)
{
	int	pos;

	pos = (map->w) * (p.y) + (p.x);
	if (map->get_exit == 1 && map->collect == 0)
		return (1);
	if (p.y < 0 || p.y >= map->h || p.x < 0 || p.x >= map->w)
		return (0);
	if (map->tile[pos].val == '1' || visit[p.y][p.x] == '1')
		return (0);
	visit[p.y][p.x] = '1';
	if (map->tile[pos].val == 'C')
		map->collect--;
	if (map->tile[pos].val == 'E')
		map->get_exit = 1;
	if (win(map, (t_item){p.val, p.qt, p.x + 1, p.y}, items, visit)
		|| win(map, (t_item){p.val, p.qt, p.x - 1, p.y}, items, visit)
		|| win(map, (t_item){p.val, p.qt, p.x, p.y + 1}, items, visit)
		|| win(map, (t_item){p.val, p.qt, p.x, p.y - 1}, items, visit))
		return (1);
	return (0);
}

void	free_visited(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	check_solution(t_map *map)
{
	t_item	player;
	t_item	items;
	int		i;
	char	**visited;

	player = map->player;
	items = map->items;
	i = 0;
	visited = (char **)malloc(map->h * sizeof(char *));
	if (!visited)
		ft_error(MALLOC_ERR);
	while (i < map->h)
	{
		visited[i] = (char *)calloc(map->w, sizeof(char));
		if (!visited[i])
			ft_error(MALLOC_ERR);
		i++;
	}
	if (win(map, player, items, visited) == 0)
		ft_error(NO_SOLUC);
	free_visited(visited, map->h);
	return (0);
}
