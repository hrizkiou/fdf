/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:54:52 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 19:05:19 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

static	int		ft_error(int code)
{
	if (code == 0)
		ft_putendl("Usage : ./fd <filename> [ case_size z_size ]");
	else if (code == 1)
		ft_putendl("Error : map Non valid");
	exit(-1);
}

int				free_data(t_data *data)
{
	int i;

	i = 0;
	if (data->coord)
	{
		while (i < data->y_len)
		{
			ft_memdel((void *)&data->coord[i]);
			i++;
		}
		free(data->coord);
	}
	return (0);
}

void			ft_init(t_data *data)
{
	data->i = 0;
	data->signal = 1;
	data->color = 0xFFFFFF;
}

int				main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error(0);
	data.fd = open(av[1], O_RDONLY);
	if (checkmap(&data) == -1)
		ft_error(1);
	else
	{
		data.fd = open(av[1], O_RDONLY);
		ft_init(&data);
		if (!ft_storemap(&data))
			return (free_data(&data));
	}
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (free_data(&data));
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr,
					WIDTH, HEIGHT, av[1])) == NULL)
		return (free_data(&data));
	drawiso(data);
	mlx_hook(data.mlx_win, 2, 0, key_hook, &data);
	mlx_loop(data.mlx_ptr);
	return (free_data(&data));
}
