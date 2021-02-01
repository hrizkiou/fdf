/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrizkiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 04:47:02 by hrizkiou          #+#    #+#             */
/*   Updated: 2019/05/17 00:01:14 by hrizkiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	int		i;
	int		n;
	int		j;

	j = -1;
	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && (s[i] != '\0'))
		i++;
	while ((s[n - 1] == ' ' || s[n - 1] == '\t' || s[n - 1] == '\n'))
		n--;
	if (n <= 0)
		return (ft_strdup(""));
	if (!(p = (char*)malloc((n - i) * sizeof(char) + 1)))
		return (NULL);
	while (s[++j] && i < n)
	{
		p[j] = s[i];
		i++;
	}
	p[j] = '\0';
	return (p);
}
