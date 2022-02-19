#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

#define TILE_SIZE 60


typedef struct	s_map
{
	char **map;
	int cols;
	int rows;
	int curr_c;
	int curr_r;
	int curr_move;
}				t_map;

typedef struct	s_game
{
	void *mlx;
	void *win;
	t_map *map;
}				t_game;

void print_curr_move(t_map *map)
{
	map->curr_move+=1;
	ft_putnbr_fd(map->curr_move, 1);
}

int key_event_func(int keycode, t_game *game)
{
	t_map *map;
	void *img;
	int width;
	int height;

	map = game->map;
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode ==13)//w
	{
		if ((0 < map->curr_r - 1) && (map->curr_r - 1 < map->rows-1) && map->map[map->curr_r-1][map->curr_c]!='1')
		{
			img=mlx_xpm_file_to_image(game->mlx,"./empty.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			map->curr_r-=1;
			img=mlx_xpm_file_to_image(game->mlx,"./human.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			//check player get money
			if (map->map[map->curr_r][map->curr_c]=='c')
				write(1, "You got a collection.\n", 22);
			ft_putstr_fd("Number of movement:", 1);
			print_curr_move(map);
			ft_putstr_fd("\n----------------------------\n",1);

		}
	}
	else if (keycode ==0)//a
	{
		if ((0 < map->curr_c - 1) && (map->curr_c - 1 < map->cols-1) && map->map[map->curr_r][map->curr_c-1]!='1')
		{
			img=mlx_xpm_file_to_image(game->mlx,"./empty.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			map->curr_c-=1;
			img=mlx_xpm_file_to_image(game->mlx,"./human.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			//check player get money
			if (map->map[map->curr_r][map->curr_c]=='c')
				write(1, "You got a collection.\n", 22);
			ft_putstr_fd("Number of movement:", 1);
			print_curr_move(map);
			ft_putstr_fd("\n----------------------------\n",1);

		}
	}
	else if (keycode ==1)//s
	{
		if ((0 < map->curr_r + 1) && (map->curr_r + 1 < map->rows-1) && map->map[map->curr_r+1][map->curr_c]!='1')
		{
			img=mlx_xpm_file_to_image(game->mlx,"./empty.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			map->curr_r+=1;
			img=mlx_xpm_file_to_image(game->mlx,"./human.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			//check player get money
			if (map->map[map->curr_r][map->curr_c]=='c')
				write(1, "You got a collection.\n", 22);
			ft_putstr_fd("Number of movement:", 1);
			print_curr_move(map);
			ft_putstr_fd("\n----------------------------\n",1);
		}

	}
	else if (keycode ==2)//d
	{
		if ((0 < map->curr_c + 1) && (map->curr_c + 1 < map->cols-1) && map->map[map->curr_r][map->curr_c+1]!='1')
		{
			img=mlx_xpm_file_to_image(game->mlx,"./empty.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			map->curr_c+=1;
			img=mlx_xpm_file_to_image(game->mlx,"./human.xpm", &width, &height);
			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*map->curr_c, TILE_SIZE*map->curr_r);
			//check player get money
			if (map->map[map->curr_r][map->curr_c]=='c')
				write(1, "You got a collection.\n", 22);
			ft_putstr_fd("Number of movement:", 1);
			print_curr_move(map);
			ft_putstr_fd("\n----------------------------\n",1);
		}
	}
	//check player will exit
	if (map->map[map->curr_r][map->curr_c]=='e')
	{
		write(1,"Game Success!\n", 14);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int destroy_event_func(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void draw_map(t_map *map, t_game *game)
{
	int i;
	int j;
	char *temp;
	void *img;
	int width;
	int height;

	i=0;
	while (i< map->rows)
	{
		temp = map->map[i];
		j=0;
		while (j < map->cols)
		{
			if (temp[j]=='1')
				img=mlx_xpm_file_to_image(game->mlx,"./wall.xpm", &width, &height);
			else if (temp[j]=='0')
				img=mlx_xpm_file_to_image(game->mlx,"./empty.xpm", &width, &height);
			else if (temp[j]=='p')
				img=mlx_xpm_file_to_image(game->mlx,"./human.xpm", &width, &height);
			else if (temp[j]=='c')
				img=mlx_xpm_file_to_image(game->mlx,"./money.xpm", &width, &height);
			else if (temp[j]=='e')
				img=mlx_xpm_file_to_image(game->mlx,"./exit.xpm", &width, &height);

			mlx_put_image_to_window(game->mlx, game->win, img, TILE_SIZE*j, TILE_SIZE*i);

			j++;
		}
		i++;
	}
}

int main(void)
{
	t_game *game;

	game=malloc(sizeof(t_game));
	if (!game)
	{
		write(1,"exit error\n",11);
	}
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, TILE_SIZE * 5,TILE_SIZE * 4,"yshon's game");


	//init image
	game->map=malloc(sizeof(t_map));
	game->map->map=malloc(sizeof(char*)*4);
	game->map->map[0]="11111";
	game->map->map[1]="100c1";
	game->map->map[2]="1p0e1";
	game->map->map[3]="11111";
	game->map->cols=5;
	game->map->rows=4;
	game->map->curr_r=2;
	game->map->curr_c=1;
	//init
	game->map->curr_move=0;



	draw_map(game->map, game);

	mlx_hook(game->win, 2, 0, &key_event_func, game);
	mlx_hook(game->win, 17, 0, &destroy_event_func, game);
	mlx_loop(game->mlx);
	return (0);
}
