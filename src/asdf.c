#include "qwer.h"



void		color(t_tamere *e, int mapX, int mapY)
{
	if (e->worldMap[mapX][mapY] == 1)
	{
		printf("1\n");
		e->color = 100 * 9 * 256;
	}
	else if (e->worldMap[mapX][mapY] == 2)
	{
		printf("2\n");
		e->color = 100 * 9;
	}
	else if (e->worldMap[mapX][mapY] == 3)
	{
		printf("3\n");
		e->color = 100 * 9 * 256 * 256;
	}
	else if (e->worldMap[mapX][mapY] == 4)
	{
		printf("4\n");
		e->color = 3 +  9 * 256 +  2 * 256 * 265;
	}
	else
	{
		printf("0\n");
		e->color = 256;
	}
}

void		pixel(t_graph *graph, t_tamere *e, int x, int y)
{
	(graph->data + y * graph->sizeline + 4 * x)[0] = e->color >> 16;
	(graph->data + y * graph->sizeline + 4 * x)[1] = e->color >> 8;
	(graph->data + y * graph->sizeline + 4 * x)[2] = e->color;
}


void	wolf(t_gg *all, t_tamere *e, t_graph *graph)
{
	int			x;

	x = 0;
	while (x < W)
	{
		printf("pox : %f, posy : %f\n", e->posX, e->posY);
		//calcul de la position et direction du rayon
		e->cameraX = 2 * x / (double)W - 1;
		e->rayPosX = e->posX;
		e->rayPosY = e->posY;
		e->rayDirX = e->dirX + e->planeX * e->cameraX;
		e->rayDirY = e->dirY + e->planeY * e->cameraY;
		//moi :
		e->mapX = (int)e->rayPosX;
		e->mapY = (int)e->rayPosY;
		//longueur du rayon dun cote x/y a un autre cote x/y
		e->deltaDistX = sqrt(1 + (e->rayDirY * e->rayDirY) / (e->rayDirX * e->rayDirX));
		e->deltaDistY = sqrt(1 + (e->rayDirX * e->rayDirX) / (e->rayDirY * e->rayDirY));
		e->hit = 0; //mur ou pas
		//calcul de la direction  du rayon et de sa longueure de moi a un mur, step = dir
		if (e->rayDirX < 0)
		{
			e->stepX = -1;
			e->sideDistX = (e->rayPosX - e->mapX) * e->deltaDistX;
			//	printf("ta mere\n");
		}
		else
		{
			e->stepX = 1;
			e->sideDistX = (e->mapX + 1.0 - e->rayPosX) * e->deltaDistX;
			printf("la pute\n");
		}
		if (e->rayDirY < 0)
		{
			e->stepY = -1;
			e->sideDistY = (e->rayPosY - e->mapY) * e->deltaDistY;
			printf("ta mere\n");
		}
		else
		{
			e->stepY = 1;
			e->sideDistY = (e->mapY + 1.0 - e->rayPosY) * e->deltaDistY;
			//	printf("la pute\n");
		}
		while (e->hit == 0)   // tant quil ny a pas de mur
		{
			if (e->sideDistX < e->sideDistY)
			{
				e->sideDistX += e->deltaDistX;
				e->mapX += e->stepX;     // mapX evolution \0/
				e->side = 0;
				//		printf("ta mere\n");
			}
			else
			{
				e->sideDistY += e->deltaDistY;
				e->mapY += e->stepY;		// mapY evolution \0/
				e->side = 1;
				//		printf("la pute\n");
			}
			if (e->worldMap[e->mapX][e->mapY] > 0)
				e->hit = 1;
		}
		if (e->side == 0)
		{
			e->perpWallDist = (e->mapX - e->rayPosX + (1 - e->stepX) / 2) / e->rayDirX;
			//		printf("ta mere\n");
		}
		else
		{
			e->perpWallDist = (e->mapY - e->rayPosY + (1 - e->stepY) / 2) / e->rayDirY;
			//		printf("la pute\n");
		}
		printf("perpWallDist : %f\n", e->perpWallDist);
		e->lineHeight = (int)(H / e->perpWallDist);
		e->drawStart = -e->lineHeight / 2 + H / 2;
		if (e->drawStart < 0)
			e->drawStart = 0;
		//printf("star : %d\n", e->drawStart);
		e->drawEnd = e->lineHeight / 2 + H / 2;
		if (e->drawEnd >= H)
			e->drawEnd = H - 1;
		//printf("end : %d\n", e->drawEnd);

		//color
		color(e, e->mapX, e->mapY);
		if (e->side == 1)
			e->color = e->color / 2;
		while (e->drawStart != e->drawEnd)
		{
			pixel(graph, e, x, e->drawStart);
			e->drawStart++;
		}

		// ----------- time
		//		e->oldTime = e->time;
		//		e->time = ;
		//		e->frameTime = (e->time = e->oldTime) / 1000.0;
		e->moveSpeed = 0.25/* e->frameTime * 5.0*/;
		e->rotSpeed = 0.05/*e->frameTime * 3.0*/;
		x++;
		printf("pox : %f, posy : %f\n", e->posX, e->posY);
	}
	mlx_key_hook(graph->win, key_event, all);
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img, 0, 0);
	mlx_loop(graph->mlx);
}

int		main(void)
{
	t_gg		*all;
	t_tamere	*e;
	t_graph		*graph;

	printf("main\n");
	all = (t_gg *)malloc(sizeof(t_gg));
	e = (t_tamere *)malloc(sizeof(t_tamere));
	graph = (t_graph *)malloc(sizeof(t_graph));

	e->worldMap[24][24] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	e->posX = 22;
	e->posY = 12;
	e->dirX = -1;
	e->dirY = 0;
	e->planeX = 0;
	e->planeY = 0.662;
	e->time = 0;
	e->oldTime = 0;

	if (!(graph->mlx = mlx_init()))
		return (0);
	if (!(graph->win = mlx_new_window(graph->mlx, W, H, "qwer")))
		return (0);
	if (!(graph->img = mlx_new_image(graph->mlx, W, H)))
		return (0);
	graph->data = mlx_get_data_addr(graph->img, &graph->bpp, &graph->sizeline, &graph->endian);
	wolf(all, e, graph);
	return (0);
}
