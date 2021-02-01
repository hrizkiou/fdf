/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:33:04 by hrizkiou          #+#    #+#             */
/*   Updated: 2020/01/12 01:54:59 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**p;
	int		i;
	int		start;
	int		end;
	int		len;

	if (!s)
		return (NULL);
	len = ft_cword(s, c);
	i = 0;
	if (!(p = (char **)(malloc(sizeof(char *) * (len + 1)))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (end > start)
			*p++ = ft_strsub(s, start, end - start);
	}
	*p = 0;
	return (p - len);
}
