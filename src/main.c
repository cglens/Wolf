/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:16:39 by cglens            #+#    #+#             */
/*   Updated: 2016/11/15 15:21:54 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_draw_line(t_tamere *e, int x)
{
	int				i;
	unsigned int	tmp;

	tmp = color(e);
	tmp = degrade(tmp, e->rc.wall_dist);
	i = -1;
	while (++i < e->draw_start)
		pixel(e, x, i, 0xffcd00);
	i--;
	while (++i < e->draw_end && i < H)
	{
		pixel(e, x, e->draw_start, e->color);
		e->draw_start++;
	}
	i--;
	while (++i < H)
		pixel(e, x, i, 0x000033);
}

void		wolf(t_tamere *e)
{
	int			x;

	x = 0;
	while (x < W)
	{
		ft_ray_init(e, x);
		e->line_height = (int)(H / e->rc.wall_dist);
		e->draw_start = -e->line_height / 2 + H / 2;
		if (e->draw_start < 0)
			e->draw_start = 0;
		e->draw_end = e->line_height / 2 + H / 2;
		if (e->draw_end >= H)
			e->draw_end = H - 1;
		color(e);
		if (e->side == 1)
			e->color = e->color / 2;
		ft_draw_line(e, x);
		x++;
	}
}

int			main(void)
{
	t_tamere	e;

	init_e(&e);
	map(&e);
	mlx_do_key_autorepeatoff(e.gr.mlx);
	mlx_loop_hook(e.gr.mlx, ft_go_move, &e);
	mlx_hook(e.gr.win, 2, (1 << 24) - 1, key_press, &e);
	mlx_hook(e.gr.win, 17, (1 << 17), ext, &e);
	mlx_key_hook(e.gr.win, key_event, &e);
	mlx_loop(e.gr.mlx);
	return (0);
}
