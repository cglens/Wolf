/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:06:18 by cglens            #+#    #+#             */
/*   Updated: 2016/11/04 16:43:50 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "qwer.h"

int		key_event(int key, t_gg *all)
{
	t_tamere	*e;
	t_graph		*graph;

	e = all->e;
	graph = all->graph;
	if (key == 53)
		exit (1);
	else if (key == 126)
	{
		ft_bzero(graph->mlx, graph->sizeline);
		if (!(e->worldMap[(int)(e->posX + e->dirX * e->moveSpeed)][(int)e->posY]))
			e->posX += e->dirX * e->moveSpeed;
		if (!(e->worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->moveSpeed)]))
			e->posY += e->dirY * e->moveSpeed;
		wolf(all, e, graph);
	}
	else if (key == 125)
	{
		ft_bzero(graph->mlx, graph->sizeline);
		if (!(e->worldMap[(int)(e->posX - e->dirX * e->moveSpeed)][(int)e->posY]))
			e->posX -= e->dirX * e->moveSpeed;
		if (!(e->worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->moveSpeed)]))
			e->posY -= e->dirY * e->moveSpeed;
		wolf(all, e, graph);
	}
	else if (key == 123)
	{
		ft_bzero(graph->mlx, graph->sizeline);
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(-e->rotSpeed) - e->dirY * sin(-e->rotSpeed);
		e->dirY = e->oldDirX * sin(-e->rotSpeed) + e->dirY * cos(-e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(-e->rotSpeed) - e->planeY * sin(-e->rotSpeed);
		e->planeY = e->oldPlaneX * sin(-e->rotSpeed) + e->planeY * cos(-e->rotSpeed);
		wolf(all, e, graph);
	}
	else if (key == 124)
	{
		ft_bzero(graph->mlx, graph->sizeline);
		e->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(e->rotSpeed) - e->dirY * sin(e->rotSpeed);
		e->dirY = e->oldDirX * sin(e->rotSpeed) + e->dirY * cos(e->rotSpeed);
		e->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(e->rotSpeed) - e->planeY * sin(e->rotSpeed);
		e->planeY = e->oldPlaneX * sin(e->rotSpeed) + e->planeY * cos(e->rotSpeed);
		wolf(all, e, graph);
	}
	return (0);
}
