#include "so_long.h"

void	print_curr_move(t_map *map)
{
	map->curr_move += 1;
	ft_putnbr_fd(map->curr_move, 1);
}

void	move_to_exit_sub(t_game *game, t_map *map)
{
	ft_putstr_fd("Number of movement:", 1);
	print_curr_move(map);
	ft_putstr_fd("\n----------------------------\nGame Success!\n", 1);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	move_to_exit(t_game *game, int *curr, int val)
{
	t_map	*map;
	void	*img;
	int		width;
	int		height;

	map = game->map;
	if (map->collect == 0)
		move_to_exit_sub(game, map);
	else
	{
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/empty.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->win, img,
			TILE_SIZE * map->curr_c, TILE_SIZE * map->curr_r);
		*curr = val;
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/exit_human.xpm", &width, &height);
		mlx_put_image_to_window(game->mlx, game->win,
			img, TILE_SIZE * map->curr_c, TILE_SIZE * map->curr_r);
		ft_putstr_fd("Number of movement:", 1);
		print_curr_move(map);
		ft_putstr_fd("\n----------------------------\n", 1);
	}
}

void	move_animation(t_game *game, int *curr, int val)
{
	t_map	*map;
	void	*img;
	int		width;
	int		height;

	map = game->map;
	if (map->map[map->curr_r][map->curr_c] == 'E')
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/exit.xpm", &width, &height);
	else
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/empty.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win, img,
		TILE_SIZE * map->curr_c, TILE_SIZE * map->curr_r);
	*curr = val;
	img = mlx_xpm_file_to_image(game->mlx,
			"./images/human.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win,
		img, TILE_SIZE * map->curr_c, TILE_SIZE * map->curr_r);
}

void	w_func(t_game *game)
{
	t_map	*map;

	map = game->map;
	if ((0 < map->curr_r - 1) && (map->curr_r - 1 < map->rows - 1)
		&& map->map[map->curr_r - 1][map->curr_c] != '1')
	{
		if (map->map[map->curr_r - 1][map->curr_c] == 'E')
		{
			move_to_exit(game, &(map->curr_r), map->curr_r - 1);
			return ;
		}
		move_animation(game, &(map->curr_r), map->curr_r - 1);
		if (map->map[map->curr_r][map->curr_c] == 'C')
		{
			write(1, "You got a collection.\n", 22);
			map->collect--;
			map->map[map->curr_r][map->curr_c] = '0';
		}
		ft_putstr_fd("Number of movement:", 1);
		print_curr_move(map);
		ft_putstr_fd("\n----------------------------\n", 1);
	}
}

void	s_func(t_game *game)
{
	t_map	*map;

	map = game->map;
	if ((0 < map->curr_r + 1) && (map->curr_r + 1 < map->rows - 1)
		&& map->map[map->curr_r + 1][map->curr_c] != '1')
	{
		if (map->map[map->curr_r + 1][map->curr_c] == 'E')
		{
			move_to_exit(game, &(map->curr_r), map->curr_r + 1);
			return ;
		}
		move_animation(game, &(map->curr_r), map->curr_r + 1);
		if (map->map[map->curr_r][map->curr_c] == 'C')
		{
			write(1, "You got a collection.\n", 22);
			map->collect--;
			map->map[map->curr_r][map->curr_c] = '0';
		}
		ft_putstr_fd("Number of movement:", 1);
		print_curr_move(map);
		ft_putstr_fd("\n----------------------------\n", 1);
	}
}

void	a_func(t_game *game)
{
	t_map	*map;

	map = game->map;
	if ((0 < map->curr_c - 1) && (map->curr_c - 1 < map->cols - 1)
		&& map->map[map->curr_r][map->curr_c - 1] != '1')
	{
		if (map->map[map->curr_r][map->curr_c - 1] == 'E')
		{
			move_to_exit(game, &(map->curr_c), map->curr_c - 1);
			return ;
		}
		move_animation(game, &(map->curr_c), map->curr_c - 1);
		if (map->map[map->curr_r][map->curr_c] == 'C')
		{
			write(1, "You got a collection.\n", 22);
			map->collect--;
			map->map[map->curr_r][map->curr_c] = '0';
		}
		ft_putstr_fd("Number of movement:", 1);
		print_curr_move(map);
		ft_putstr_fd("\n----------------------------\n", 1);
	}
}

void	d_func(t_game *game)
{
	t_map	*map;

	map = game->map;
	if ((0 < map->curr_c + 1) && (map->curr_c + 1 < map->cols - 1)
		&& map->map[map->curr_r][map->curr_c + 1] != '1')
	{
		if (map->map[map->curr_r][map->curr_c + 1] == 'E')
		{
			move_to_exit(game, &(map->curr_c), map->curr_c + 1);
			return ;
		}
		move_animation(game, &(map->curr_c), map->curr_c + 1);
		if (map->map[map->curr_r][map->curr_c] == 'C')
		{
			write(1, "You got a collection.\n", 22);
			map->collect--;
			map->map[map->curr_r][map->curr_c] = '0';
		}
		ft_putstr_fd("Number of movement:", 1);
		print_curr_move(map);
		ft_putstr_fd("\n----------------------------\n", 1);
	}
}

int	key_event_func(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == 13)
		w_func(game);
	else if (keycode == 0)
		a_func(game);
	else if (keycode == 1)
		s_func(game);
	else if (keycode == 2)
		d_func(game);
	return (0);
}

int	destroy_event_func(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	draw_map_element(t_game *game, char c, int i, int j)
{
	void	*img;
	int		width;
	int		height;

	if (c == '1')
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/wall.xpm", &width, &height);
	else if (c == '0')
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/empty.xpm", &width, &height);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/human.xpm", &width, &height);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/money.xpm", &width, &height);
	else
		img = mlx_xpm_file_to_image(game->mlx,
				"./images/exit.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->win,
		img, TILE_SIZE * j, TILE_SIZE * i);
}

void	draw_map(t_map *map, t_game *game)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < map->rows)
	{
		temp = map->map[i];
		j = 0;
		while (j < map->cols)
		{
			draw_map_element(game, temp[j], i, j);
			j++;
		}
		i++;
	}
}

int	row_count_func(int fd)
{
	char	*p;
	int		ret;

	ret = 0;
	get_next_line(fd, &p);
	while (*p)
	{
		ret++;
		free(p);
		get_next_line(fd, &p);
	}
	free(p);
	return (ret);
}

void	read_map(int fd, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		get_next_line(fd, &(map->map[i]));
		i++;
	}
}

int	init_variable(t_flag *flag, char *s, t_map *map)
{
	int	i;

	i = 0;
	flag->pflag = 0;
	flag->eflag = 0;
	flag->cflag = 0;
	while (*s)
	{
		if (*s != '1' && *s != '0' && *s != 'E' && *s != 'C' && *s != 'P')
			return (0);
		s++;
		i++;
	}
	map->cols = i;
	return (1);
}

int	check_row(char *s, t_flag *flag, t_map *map, int j)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == 'C')
			(flag->cflag)++;
		else if (*s == 'E')
			flag->eflag = 1;
		else if (*s == 'P')
		{
			(flag->pflag)++;
			map->curr_c = i;
			map->curr_r = j;
		}
		else if (*s != '1' && *s != '0' && *s != 'E'
			&& *s != 'C' && *s != 'P')
			return (0);
		i++;
		s++;
	}
	if (i != map->cols)
		return (0);
	return (1);
}

int	check_wall(t_map *map)
{
	int		i;
	char	*s;

	s = map->map[0];
	while (*s)
	{
		if (*s != '1')
			return (0);
		s++;
	}
	i = 1;
	while (i < map->rows - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->cols - 1] != '1')
			return (0);
		i++;
	}
	s = map->map[map->rows - 1];
	while (*s)
	{
		if (*s != '1')
			return (0);
		s++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	int		j;
	t_flag	flag;

	if (!init_variable(&flag, map->map[0], map))
		return (0);
	j = 0;
	while (j < map->rows)
	{
		if (!check_row(map->map[j], &flag, map, j))
			return (0);
		j++;
	}
	if (flag.eflag == 0 || flag.cflag == 0 || flag.pflag != 1)
		return (0);
	map->collect = flag.cflag;
	if (map->cols < 3 || map->rows < 3)
		return (0);
	if (!check_wall(map))
		return (0);
	return (1);
}

int	check_file_name(char *name, t_map *map)
{
	int		leng;
	char	*s;
	int		fd;

	leng = 0;
	s = name;
	while (*s)
	{
		leng++;
		s++;
	}
	s = name;
	if (leng > 4 && s[leng - 4] == '.' && s[leng - 3] == 'b'
		&& s[leng - 2] == 'e' && s[leng - 1] == 'r')
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
			return (0);
		map->rows = row_count_func(fd);
		close(fd);
		if (map->rows == 0)
			return (0);
		map->map = (char **)malloc(sizeof(char *) * map->rows);
		if (!(map->map))
			return (0);
		fd = open(name, O_RDONLY);
		if (fd == -1)
		{
			free(map->map);
			return (0);
		}
		read_map(fd, map);
		if (!check_map(map))
		{
			int	i;

			i = 0;
			while (i < map->rows)
			{
				free(map->map[i]);
				i++;
			}
			free(map->map);
			return (0);
		}
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	game->mlx = mlx_init();
	game->map = malloc(sizeof(t_map));
	if (!(game->map))
	{
		write(1, "Error\n", 6);
		free(game);
		return (0);
	}
	if (!check_file_name(argv[1], game->map))
	{
		write(1, "Error\n", 6);
		free(game->map);
		free(game);
		return (0);
	}
	game->map->curr_move = 0;
	game->win = mlx_new_window(game->mlx, TILE_SIZE * game->map->cols,
			TILE_SIZE * game->map->rows, "yshon's game");
	draw_map(game->map, game);
	mlx_hook(game->win, 2, 0, &key_event_func, game);
	mlx_hook(game->win, 17, 0, &destroy_event_func, game);
	mlx_loop(game->mlx);
	return (0);
}
