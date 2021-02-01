/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 00:13:20 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/05/18 05:58:42 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = ft_strlen(dst);
	j = 0;
	if (size <= i)
		return (size + ft_strlen(src));
	else
		while (i + j < size - 1 && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
