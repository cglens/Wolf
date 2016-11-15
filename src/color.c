/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:58:04 by cglens            #+#    #+#             */
/*   Updated: 2016/11/15 15:21:35 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			pixel(t_tamere *e, int x, int y, int color)
{
	(e->gr.data + y * e->gr.sizeline + 4 * x)[0] = color >> 16;
	(e->gr.data + y * e->gr.sizeline + 4 * x)[1] = color >> 8;
	(e->gr.data + y * e->gr.sizeline + 4 * x)[2] = color;
}

unsigned int	color(t_tamere *e)
{
	if (e->side == 1)
	{
		if ((e->rc.step_x == -1 && e->rc.step_y == -1) ||
				(e->rc.step_x == 1 && e->rc.step_y == -1))
			e->color = 0x663300;
		else if ((e->rc.step_x == -1 && e->rc.step_y == 1) ||
				(e->rc.step_x == 1 && e->rc.step_y == 1))
			e->color = 0x333366;
	}
	else if ((e->rc.step_x == -1 && e->rc.step_y == -1) ||
			(e->rc.step_x == -1 && e->rc.step_y == 1))
		e->color = 0x003399;
	else
		e->color = 0x333399;
	return (e->color);
}

unsigned int	degrade(unsigned int color, double dist)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = color;
	g = color >> 8;
	b = color >> 16;
	dist = 7 / (100 / dist);
	if (dist > 0.9)
		dist = 0.9;
	if (r > 0)
		r = r - (r * dist);
	if (g > 0)
		g = g - (g * dist);
	if (b > 0)
		b = b - (b * dist);
	return ((r << 16) + (g << 8) + b);
}
