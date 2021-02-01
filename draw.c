/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 01:55:52 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 19:17:27 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	dda(t_data data, t_map xy0, t_map xy1, int color)
{
	double dx;
	double dy;
	double step;
	double x;
	double y;

	x = xy0.x;
	y = xy0.y;
	dx = xy1.x - xy0.x;
	dy = xy1.y - xy0.y;
	step = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	while (1)
	{
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, color);
		if (round(x) == xy1.x && round(y) == xy1.y)
			break ;
		x += (dx / step);
		y += (dy / step);
	}
}

void	drawiso(t_data data)
{
	mlx_clear_window(data.mlx_ptr, data.mlx_win);
	data.i = -1;
	while (++data.i < data.y_len - 1)
	{
		data.j = -1;
		while (++data.j < data.x_len)
			dda(data, iso(data, data.i, data.j),
					iso(data, data.i + 1, data.j), data.color);
	}
	data.j = -1;
	while (++data.j < data.x_len - 1)
	{
		data.i = -1;
		while (++data.i < data.y_len)
			dda(data, iso(data, data.i, data.j),
					iso(data, data.i, data.j + 1), data.color);
	}
	ft_menu(data);
}

void	drawp_h(t_data data)
{
	mlx_clear_window(data.mlx_ptr, data.mlx_win);
	data.i = -1;
	while (++data.i < data.y_len - 1)
	{
		data.j = -1;
		while (++data.j < data.x_len)
			dda(data, parallel(data, data.i, data.j),
					parallel(data, data.i + 1, data.j), data.color);
	}
	data.j = -1;
	while (++data.j < data.x_len - 1)
	{
		data.i = -1;
		while (++data.i < data.y_len)
			dda(data, parallel(data, data.i, data.j),
					parallel(data, data.i, data.j + 1), data.color);
	}
	ft_menu(data);
}

t_map	iso(t_data data, int i, int j)
{
	t_map t;

	t.x = WIDTH / 2 + (data.coord[i][j].x - data.coord[i][j].y) * cos(0.523599);
	t.y = HEIGHT / 3 + ((data.coord[i][j].x + data.coord[i][j].y) \
			* sin(0.523599) - data.coord[i][j].z);
	return (t);
}

t_map	parallel(t_data data, int i, int j)
{
	t_map t;

	t.x = WIDTH / 2 + data.coord[i][j].x;
	t.y = HEIGHT / 2 + data.coord[i][j].y;
	return (t);
}
