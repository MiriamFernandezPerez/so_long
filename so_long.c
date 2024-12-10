/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:27:00 by mirifern          #+#    #+#             */
/*   Updated: 2024/06/05 21:33:19 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(char *path, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(NO_FILE);
	line = (char *)get_next_line(fd);
	while (line)
	{
		if (!map->w || map->w == 0)
			map->w = (int)ft_strlen(line) - 1;
		else if (line[map->w] != '\n')
			ft_error(IRREG_MAP);
		else if (map->w != (int)ft_strlen(line) - 1)
			ft_error(IRREG_MAP);
		free(line);
		line = get_next_line(fd);
		(map->h)++;
	}
	if (map->w == 0)
		ft_error(EMPTY_MAP);
	if (80 * map->w > 3840 || 80 * map->h > 1840)
		ft_error(TOO_BIG);
	close(fd);
}

int	check_ac(int ac)
{
	if (ac == 1)
		ft_error(NO_ARGS);
	else if (ac > 2)
		ft_error(TOO_ARGS);
	return (1);
}

int	check_av(char *av, int c)
{
	int		i;
	char	*ext;
	int		flag;

	i = 0;
	ext = ft_strrchr(av, c);
	flag = 0;
	while (av[i] != '\0')
	{
		if (av[i] == (unsigned char)c)
			flag = i;
		i++;
	}
	if (ext != NULL)
	{
		if (av[flag - 1] == '\0' || av[flag - 1] == '/')
			ft_error(NO_NAME);
		if (ft_strncmp(ext, ".ber", 4) == 0
			&& ft_strlen(ext) == 4 && ft_strlen(av) > 4)
			return (1);
		else
			ft_error(TYPE_ARG);
	}
	return (0);
}

void	init_map(t_map **map)
{
	(*map)->w = 0;
	(*map)->h = 0;
	(*map)->walls = 0;
	(*map)->spaces = 0;
	(*map)->collect = 0;
	(*map)->get_exit = 0;
	(*map)->player.val = 0;
	(*map)->player.qt = 0;
	(*map)->items.val = 0;
	(*map)->items.qt = 0;
	(*map)->exit.val = 0;
	(*map)->exit.qt = 0;
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error(MALLOC_ERR);
	init_map(&map);
	if (check_ac(ac))
	{
		if (check_av(av[1], 46))
			check_arg(av[1], map);
		else
			ft_error (NO_NAME);
	}
	create_tile(map, av[1]);
	init_game(map);
	free(map->tile);
	free(map);
	return (0);
}
