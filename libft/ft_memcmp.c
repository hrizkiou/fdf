/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:53:37 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/05/16 23:40:35 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					i;
	const unsigned char	*s1_p;
	const unsigned char	*s2_p;

	i = 0;
	s1_p = s1;
	s2_p = s2;
	while (n--)
	{
		if (s1_p[i] != s2_p[i])
		{
			return ((int)(s1_p[i] - s2_p[i]));
		}
		i++;
	}
	return (0);
}
