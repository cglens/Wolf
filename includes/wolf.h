/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:21:38 by cglens            #+#    #+#             */
/*   Updated: 2016/11/16 14:09:14 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# define W 2080
# define H 1500

typedef struct		s_raycast
{
	double			plane_x;
	double			plane_y;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_dist;
	int				step_x;
	int				step_y;
}					t_raycast;

typedef struct		s_move
{
	int				up;
	int				down;
	int				right;
	int				left;
	double			move_speed;
	int				tmp_speed;
	double			rot_speed;
	double			camera;
	int				map_x;
	int				map_y;

}					t_move;

typedef struct		s_graph
{
	void			*mlx;
	void			*win;
	void			*mlx_2;
	void			*win_2;
	void			*img;
	int				bpp;
	int				endian;
	int				sizeline;
	char			*data;
}					t_graph;

typedef struct		s_tamere
{
	t_move			move;
	t_graph			gr;
	t_raycast		rc;
	int				fd;
	int				**world_map;
	int				col;
	int				lig;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				rgb;
	double			frametime;
	double			old_dir_x;
	double			old_plane_x;
	unsigned int	color;
}					t_tamere;

void				map(t_tamere *e);
void				init_e(t_tamere *e);
void				ft_move_up(t_tamere *e);
void				ft_move_down(t_tamere *e);
void				ft_move_right(t_tamere *e);
void				ft_move_left(t_tamere *e);
int					ft_go_move(t_tamere *e);
void				wolf(t_tamere *e);
void				ft_ray_init(t_tamere *e, int x);
int					key_event(int key, t_tamere *e);
int					key_press(int key, t_tamere *e);
int					ext(void);
unsigned int		color(t_tamere *e);
void				pixel(t_tamere *e, int x, int y, int color);

#endif
