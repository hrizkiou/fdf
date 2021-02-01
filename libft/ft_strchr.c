/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 02:14:13 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/05/18 05:58:33 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t n;

	n = ft_strlen(s) + 1;
	while (n--)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	return (NULL);
}
