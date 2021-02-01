/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:53:42 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 18:02:01 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fdf.h"

void	ft_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i++])
		ft_strdel(&ptr[i]);
	ft_memdel((void **)ptr);
}

int		ft_return(char **ptr, char *str, int err)
{
	if (ptr)
		ft_free(ptr);
	if (str)
		ft_strdel(&str);
	return (err);
}

int		ft_maplen(char **map)
{
	int				i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int		checkmap(t_data *data)
{
	int				a;
	int				err;
	char			*str;
	char			**map;

	a = -1;
	data->y_len = 0;
	str = NULL;
	while ((err = get_next_line(data->fd, &str)) > 0)
	{
		map = ft_strsplit(str, ' ');
		if (a == -1)
			a = ft_maplen(map);
		data->x_len = ft_maplen(map);
		if (a > 0 && a <= data->x_len)
			data->y_len++;
		else
			return (ft_return(map, str, -1));
		ft_return(map, str, 0);
	}
	close(data->fd);
	return (ft_return(NULL, str, err));
}
