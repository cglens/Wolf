/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:58:04 by cglens            #+#    #+#             */
/*   Updated: 2016/11/16 14:29:38 by cglens           ###   ########.fr       */
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
			e->color = 0x888888;
		else if ((e->rc.step_x == -1 && e->rc.step_y == 1) ||
				(e->rc.step_x == 1 && e->rc.step_y == 1))
			e->color = 0x606060;
	}
	else if ((e->rc.step_x == -1 && e->rc.step_y == -1) ||
			(e->rc.step_x == -1 && e->rc.step_y == 1))
		e->color = 0x385386;
	else
		e->color = 0x596b9e;
	return (e->color);
}
