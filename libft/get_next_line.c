/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <hrizkiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:06:06 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/02/16 01:21:14 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*ft_free(char *str, char *tmp)
{
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

static	void		ft_read_line(int fd, char **str)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		ft_strdel(&tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
}

static	int			ft_count_char(int fd, char **str)
{
	int				i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	static	char	*str[MAX_FD];
	int				i;

	if (!line || read(fd, str, 0) < 0 || (fd < 0 && fd > MAX_FD))
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	ft_read_line(fd, str);
	i = ft_count_char(fd, str);
	*line = ft_strsub(str[fd], 0, i);
	if (ft_strlen(str[fd]) == 0)
		return (0);
	if (str[fd][i] == '\n')
		str[fd] = ft_free(str[fd], ft_strdup(str[fd] + i + 1));
	else
		str[fd] = ft_free(str[fd], ft_strdup(str[fd] + i));
	return (1);
}
