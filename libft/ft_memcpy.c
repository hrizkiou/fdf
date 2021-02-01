/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:05:22 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/05/18 00:53:57 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *p_dst;

	p_dst = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (p_dst);
}
