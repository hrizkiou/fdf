/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 05:36:51 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 19:03:38 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

static int	ft_return0(char **ptr, char *str, int err)
{
	int i;

	i = 0;
	if (ptr)
	{
		while (ptr[i++])
			ft_free(ptr);
		ft_free(ptr);
	}
	if (str)
		ft_strdel(&str);
	return (err);
}

static void	ft_store_coord(t_data *data, char **map, int i, int j)
{
	data->coord[i][j].x = j * (WIDTH * 0.5 / data->x_len);
	data->coord[i][j].y = i * (HEIGHT * 0.5 / data->y_len);
	data->coord[i][j].z = atoi(map[j]) * 30;
}

int			ft_storemap(t_data *data)
{
	int		i;
	int		j;
	char	*str;
	char	**map;

	i = 0;
	if (!(data->coord = (t_map**)(ft_memalloc(sizeof(t_map *) * data->y_len))))
		return (0);
	while (get_next_line(data->fd, &str) > 0)
	{
		map = ft_strsplit(str, ' ');
		data->a = ft_maplen(map);
		if (!(data->coord[i] = (t_map*)(ft_memalloc(sizeof(t_map) * data->a))))
			return (ft_return0(map, str, 0));
		j = -1;
		while (++j < data->a)
			ft_store_coord(data, map, i, j);
		data->coord[i][j].y = i;
		i++;
		ft_return(map, str, 0);
	}
	ft_strdel(&str);
	return ((!close(data->fd)) ? 1 : 0);
}
