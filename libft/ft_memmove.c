/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:53:00 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/05/17 08:45:12 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *p_dst;
	char *p_src;

	p_dst = (char *)dst;
	p_src = (char *)src;
	if (p_dst < p_src)
		return (ft_memcpy(p_dst, p_src, len));
	while (len--)
		p_dst[len] = p_src[len];
	return (p_dst);
}
