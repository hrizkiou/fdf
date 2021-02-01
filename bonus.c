/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 02:18:25 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 19:15:25 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	ft_move(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->y_len)
	{
		j = -1;
		while (++j < data->x_len)
			if (data->move == 1)
			{
				data->coord[i][j].x = data->coord[i][j].x - 9;
				data->coord[i][j].y = data->coord[i][j].y - 9;
			}
			else if (data->move == -1)
			{
				data->coord[i][j].x = data->coord[i][j].x + 9;
				data->coord[i][j].y = data->coord[i][j].y + 9;
			}
			else if (data->move == 2)
				data->coord[i][j].x = data->coord[i][j].x + 9;
			else if (data->move == -2)
				data->coord[i][j].x = data->coord[i][j].x - 9;
	}
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
}

void	ft_increase_z(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->y_len)
	{
		j = -1;
		while (++j < data->x_len)
		{
			if (data->coord[i][j].z > 0 || data->coord[i][j].z < 0)
				data->coord[i][j].z = data->coord[i][j].z + 9;
		}
	}
	drawiso(*data);
}

void	ft_decrease_z(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->y_len)
	{
		j = -1;
		while (++j < data->x_len)
		{
			if (data->coord[i][j].z > 0 || data->coord[i][j].z < 0)
				data->coord[i][j].z = data->coord[i][j].z - 9;
		}
	}
	drawiso(*data);
}

void	ft_menu(t_data data)
{
	int i;
	int j;

	i = -1;
	while (++i < 300)
	{
		j = -1;
		while (++j < 300)
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j, 0x123456);
	}
	mlx_string_put(data.mlx_ptr, data.mlx_win, 5, 1,
			0x008000, "        How to use !");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 5, 40,
			0xFFFFFF, "         (p & i)");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 5, 80,
			0xFFFFFF, "    <-left right move->");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 5, 120,
			0xFFFFFF, "      up & down move");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 5, 160,
			0xFFFFFF, "   W+ or S- to increase z");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 5, 200,
			0xFFFFFF, " R or G or B to change color");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 5, 240,
			0xFFFFFF, "    Escape to leave !");
}
