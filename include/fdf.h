/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:55:51 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 18:19:10 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct		s_map
{
	int				x;
	int				y;
	int				z;
}					t_map;
typedef struct		s_data
{
	int				a;
	int				fd;
	int				i;
	int				j;
	t_map			**coord;
	int				x_len;
	int				y_len;
	int				move;
	int				color;
	int				increase;
	int				decrease;
	int				signal;
	void			*mlx_ptr;
	void			*mlx_win;
}					t_data;
int					checkmap(t_data *data);
int					ft_maplen(char **map);
int					ft_storemap(t_data *data);
void				dda(t_data data, t_map xy0, t_map xy1, int color);
t_map				iso(t_data data, int i, int j);
t_map				parallel(t_data data, int i, int j);
void				ft_menu(t_data data);
void				drawiso(t_data data);
void				drawp_h(t_data data);
void				ft_move(t_data *data);
void				ft_increase_z(t_data *data);
void				ft_decrease_z(t_data *data);
int					key_hook(int key, t_data *data);
void				transformation_ud(int key, t_data *data);
void				transformation_lr(int key, t_data *data);
void				ft_changeprojection(int key, t_data *data);
void				transformation_color(int key, t_data *data);
void				ft_free(char **ptr);
int					free_data(t_data *data);
int					ft_return(char **ptr, char *str, int err);
void				ft_close(t_data *data);
#endif
