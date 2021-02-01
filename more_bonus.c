/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:41:09 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 01:04:22 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	transformation_color(int key, t_data *data)
{
	if (key == 15)
	{
		data->color = 0xFF0000;
		if (data->signal == 1)
			drawiso(*data);
		if (data->signal == 0)
			drawp_h(*data);
	}
	else if (key == 5)
	{
		data->color = 0x00ff00;
		if (data->signal == 1)
			drawiso(*data);
		if (data->signal == 0)
			drawp_h(*data);
	}
	else if (key == 11)
	{
		data->color = 0x0000ff;
		if (data->signal == 1)
			drawiso(*data);
		if (data->signal == 0)
			drawp_h(*data);
	}
}
