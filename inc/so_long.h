/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirifern <mirifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:30:36 by mirifern          #+#    #+#             */
/*   Updated: 2024/06/05 23:26:45 by mirifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include "../my_libft/libft.h"
# include "../mlx_mac/mlx.h"
# include "../mlx_linux/mlx.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>

// ERRORS
# define NO_ARGS "Error\nWrong number of arguments\n"
# define TOO_ARGS "Error\nWrong number of arguments\n"
# define TYPE_ARG "Error\nBad extension\n"
# define NO_NAME "Error\nError name file\n"
# define NO_FILE "Error\nFile doesnt exits or permission denied\n"
# define MALLOC_ERR "Error\nMalloc failed\n"
# define TOO_BIG "Error\nMap too big\n"
# define EMPTY_MAP "Error\nEmpty Map\n"
# define INV_MAP "Error\nInvalid Map\n"
# define NO_RECT "Error\nNo rectangular\n"
# define IRREG_MAP "Error\nIrregular Map\n"
# define INV_MAP_CHAR "Error\nWrong characters\n"
# define NO_PLAYER "Error\nNo player\n"
# define TOO_PLAYERS "Error\nDuplicate player\n"
# define NO_COLLECTS "Error\nNo object\n"
# define NO_EXIT "Error\nNo exit\n"
# define TOO_EXITS "Error\nDuplicate exit\n"
# define WALL_ERR "Error\nNo surrounded by walls\n"
# define NO_SOLUC "Error\nMap without solution\n"
# define NO_SPRITE "Error\nCant open sprite file. NO MUEVAS EL EJECUTABLE\n"

// KEYS
# define ESC 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

// SPRITES
# define FLOOR "./sprites/floor0.xpm"
# define WALL "./sprites/wall0.xpm"
# define DIAMOND1 "./sprites/diamond0.xpm"
# define DIAMOND2 "./sprites/diamond1.xpm"
# define DIAMOND3 "./sprites/diamond2.xpm"
# define DIAMOND4 "./sprites/diamond3.xpm"
# define DIAMOND5 "./sprites/diamond4.xpm"
# define TRAPDOOR "./sprites/trapdoor0.xpm"
# define TRAPDOOR1 "./sprites/opentrapdoor1.xpm"
# define TRAPDOOR2 "./sprites/opentrapdoor2.xpm"
# define TRAPDOOR3 "./sprites/opentrapdoor3.xpm"
# define TRAPDOOR4 "./sprites/opentrapdoor4.xpm"
# define STEVE1 "./sprites/steve0.xpm"
# define STEVE2 "./sprites/steve1.xpm"
# define PATH "./sprites/"
# define EXT ".xpm"

typedef struct s_item
{
	char	val;
	int		qt;
	int		x;
	int		y;
}	t_item;

typedef struct s_tile
{
	char	val;
	int		x;
	int		y;
}	t_tile;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_map
{
	int		w;
	int		h;
	int		walls;
	int		spaces;	
	int		collect;
	int		get_exit;
	t_item	player;
	t_item	items;
	t_item	exit;
	t_tile	*tile;
}		t_map;

typedef struct s_vars
{
	int		exit;
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int		moves;
	char	**ffile;
	char	**wfile;
	char	**dfile;
	char	**tfile;
	char	**ofile;
	char	**sfile;
	t_map	*data;
	char	**map;
	t_data	img;
}			t_vars;

//so_long.c
void	check_arg(char *av, t_map *map);
int		check_ac(int ac);
int		check_av(char *av, int c);
void	init_map(t_map **map);
int		main(int ac, char **av);

//utils
void	ft_error(char *s);
char	**ft_free(char **ptr, int index);
int		render(t_vars *game);

//manage_maps.c
int		check_chars(t_map *map);
void	check_map(t_map *map, t_tile *tile);
void	fill_tile(char *line, t_tile *tile, int *index, int y);
void	create_tile(t_map *map, char *path);

//check_sprites
void	check_walls(t_map *map);
void	check_player(int player);
void	check_items(int items);
void	check_exit(int exit);
void	check_char_item(t_map *map, char c, int i);

//check_solution
int		win(t_map *map, t_item play, t_item items, char **visit);
void	free_visited(char **visited, int height);
int		check_solution(t_map *map);

//init_game
int		close_window(t_vars *game);
void	move_to_e(t_vars *game, int c);
int		moves(int c, t_vars *game);
void	create_map(t_vars *game, t_map *map);
int		init_game(t_map *map);

//moves
void	ft_up(t_vars *game);
void	ft_down(t_vars *game);
void	ft_left(t_vars *game);
void	ft_right(t_vars *game);

//print_game
void	print_floor(t_vars *game);
void	print_item(t_vars *g, int x, int y, char c);
void	check_open(char *path);
void	init_sprites(t_vars *game);
void	print_game(t_vars *game);

#endif
