#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"
# define TILE_SIZE 60


typedef struct	s_map
{
	char **map;
	int cols;
	int rows;
	int curr_c;
	int curr_r;
	int curr_move;
	int collect;
}				t_map;

typedef struct	s_game
{
	void *mlx;
	void *win;
	t_map *map;
}				t_game;

#endif
