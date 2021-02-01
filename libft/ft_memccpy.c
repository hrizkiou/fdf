/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 02:42:29 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/05/16 23:40:55 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_src;
	unsigned char	*p_dst;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if (p_src[i] == (unsigned char)c)
			return ((char*)p_dst + i + 1);
		i++;
	}
	return (NULL);
}
