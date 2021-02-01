/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 05:03:46 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 17:42:46 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

int		key_hook(int key, t_data *data)
{
	if (key == 34 || key == 35)
		ft_changeprojection(key, data);
	if (key == 123 || key == 124)
		transformation_lr(key, data);
	if (key == 125 || key == 126)
		transformation_ud(key, data);
	if (data->signal == 1 && key == 13)
		ft_increase_z(data);
	if (data->signal == 1 && key == 1)
		ft_decrease_z(data);
	if (data->signal == 1 && (key == 5 || key == 11 || key == 15))
		transformation_color(key, data);
	if (data->signal == 0 && (key == 5 || key == 11 || key == 15))
		transformation_color(key, data);
	if (key == 53)
		ft_close(data);
	return (0);
}

void	transformation_ud(int key, t_data *data)
{
	if (key == 125)
	{
		data->move = -1;
		ft_move(data);
		if (data->signal == 0)
			drawp_h(*data);
		else
			drawiso(*data);
	}
	if (key == 126)
	{
		data->move = 1;
		ft_move(data);
		if (data->signal == 0)
			drawp_h(*data);
		else
			drawiso(*data);
	}
}

void	transformation_lr(int key, t_data *data)
{
	if (key == 123)
	{
		data->move = -2;
		ft_move(data);
		if (data->signal == 0)
			drawp_h(*data);
		else
			drawiso(*data);
	}
	if (key == 124)
	{
		data->move = 2;
		ft_move(data);
		if (data->signal == 0)
			drawp_h(*data);
		else
			drawiso(*data);
	}
}

void	ft_changeprojection(int key, t_data *data)
{
	if (key == 34)
	{
		data->signal = 1;
		drawiso(*data);
	}
	if (key == 35)
	{
		data->signal = 0;
		drawp_h(*data);
	}
}

void	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free_data(data);
	exit(0);
}
