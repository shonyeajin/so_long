#include "so_long.h"

typedef struct s_map
{
	char **map;
	int cols;
	int rows;
	int curr_c;
	int curr_r;
	int curr_move;
}			t_map;

int row_count_func(int fd)
{
	char *p;
	int ret;

	ret = 0;
	get_next_line(fd, &p);
	while (*p)
	{
		ret++;
		get_next_line(fd, &p);
	}
	return (ret);
}

void	read_map(int fd, t_map *map)
{
	int i;
	
	i=0;
	while (i< map->rows)
	{
		get_next_line(fd, &(map->map[i]));
		i++;
	}
}

int check_map(t_map *map)
{
	//1. 0, 1, C, P ,E 로만 이루어져있는지 ->0
	//2. 벽으로 둘러져 있는지 -> 이게 가능하려면 map->rows>=3이어야 함.map->cols>=3 ->0
	//3. C, P, E가 적어도 한개씩 있는지, P는 하나인지->0
	//4. 지도가 직사각형인지 ->0
	int i;
	int j;
	char *s;
	int cflag;
	int pflag;
	int eflag;

	pflag = 0;
	eflag = 0;
	cflag = 0;
	s = map->map[0];
	i = 0;
	while (*s)
	{
		if (*s == 'C')
			cflag = 1;
		else if (*s == 'E')
			eflag = 1;
		else if (*s == 'P')
			pflag++;
		else if (*s != '1' && *s !='0' && *s !='E' && *s !='C' && *s != 'P')
			return (0);
		s++;
		i++;
	}
	map->cols = i;
	j = 0;
	while (j < map->rows)
	{
		s=map->map[j];
		i =0;
		while (*s)
		{
			if (*s == 'C')
				cflag = 1;
			else if (*s == 'E')
				eflag = 1;
			else if (*s == 'P')
				pflag++;
			else if (*s != '1' && *s !='0' && *s !='E' && *s !='C' && *s != 'P')
				return (0);
			i++;
			s++;
		}
		if (i != map->cols)
			return (0);
		j++;
	}
	if (eflag ==0 || cflag==0 || pflag != 1)
		return (0);
	if (map->cols < 3 || map->rows < 3)
		return(0);
	s=map->map[0];
	while (*s)
	{
		if(*s != '1')
			return (0);
		s++;
	}
	i = 1;
	while (i < map->rows - 1)
	{
		if (map->map[i][0]!='1' || map->map[i][map->cols-1]!='1')
			return (0);
		i++;
	}
	s = map->map[map->rows - 1];
	while (*s)
	{
		if(*s != '1')
			return (0);
		s++;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	//file name check
	int leng;
	char *name;
	int fd;

	leng = 0;
	name = argv[1];
	while (*name)
	{
		leng++;
		name++;
	}
	name=argv[1];
	if (leng > 4 && name[leng-4] == '.' && name[leng - 3] == 'b' && name[leng-2] == 'e' && name[leng-1] == 'r')
	{
		if ((fd=open(name, O_RDONLY)) == -1)
		{
			write(1,"Error\n",6);
			return (0);
		}
		//read file
		t_map *map;

		map=malloc(sizeof(t_map));
		//몇줄인지 gnl 호출해서 알아봄
		map->rows = row_count_func(fd);
		close(fd);
		if (map->rows == 0)
		{
			write(1,"Erorr\n", 6);
			return (0);
		}
		map->map=(char **)malloc(sizeof(char *)*map->rows);
		//map->map각각에 문자열 저장
		if ((fd=open(name, O_RDONLY)) == -1)
		{
			write(1,"Error\n",6);
			return (0);
		}
		read_map(fd, map);
		//읽은 맵 형식 검사
		//1. 0, 1, C, P ,E 로만 이루어져있는지
		//2. 벽으로 둘러져 있는지
		//3. C, P, E가 적어도 한개씩 있는지, P는 하나인지
		//4. 지도가 직사각형인지
		int ret;
		ret = check_map(map);
		if (ret==0)
		{
			write(1,"Error\n",6);
			return(0);
		}



	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	

}

