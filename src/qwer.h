#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
#include "../libft/includes/libft.h"
#define W 512
#define H 384

typedef struct      s_graph
{
	void            *mlx;
	void            *win;
	void            *img;
	int             bpp;
	int             endian;
	int             sizeline;
	char            *data;
}					t_graph;

typedef struct		s_tamere
{
	int				**worldMap;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			time;
	double			oldTime;
	double			cameraX;
	double			cameraY;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				rgb;
	double			frameTime;
	double			moveSpeed;
	double			rotSpeed;
	double			oldDirX;
	double			oldPlaneX;
	int				color;
}					t_tamere;

typedef struct		s_gg
{
	t_graph			*graph;
	t_tamere		*e;
}					t_gg;

void	wolf(t_gg *all, t_tamere  *e, t_graph *graph);
//void	color(t_tamere *e, int mapX, int mapY);
//void	pixel(t_graph *graph, t_tamere *e, int x, int y);
int		key_event(int key, t_gg *all);
