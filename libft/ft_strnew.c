/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 23:25:18 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/04/29 00:04:56 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char*)malloc(size * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	else
		while (size)
		{
			p[i] = '\0';
			i++;
			size--;
		}
	p[i] = '\0';
	return (p);
}
