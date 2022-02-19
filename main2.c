#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_data;

typedef struct	s_vars
{
	void *mlx;
	void *win;
}				t_vars;

int exit_hook()
{
	exit(0);
}

//esc key press event
int key_hook(int keycode, t_vars *vars)
{
	if (keycode ==53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst=data->addr+(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_vars vars;
	t_data image;

	vars.mlx=mlx_init();
	vars.win=mlx_new_window(vars.mlx, 1000, 500, "Hellow World!");
	/*
	image.img=mlx_new_image(vars.mlx,500, 500);
	image.addr=mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	int i;
	i=0;
	while (i < 500)
	{
		int j;
		j=0;
		while(j < 500)
		{
			//mlx_pixel_put(mlx_ptr,win_ptr, i,j, 0x00FFFFFF);
			my_mlx_pixel_put(&image,i,j, 0x00FFFFFF);
			j++;
		}
		i++;
	}
	*/
	int width;
	int height;
	image.img=mlx_xpm_file_to_image(vars.mlx, "./apple.xpm", &width,&height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);//esc key press event
	mlx_hook(vars.win, 17, 0, exit_hook, 0);// close button press event
	mlx_loop(vars.mlx);

	return (0);
}
