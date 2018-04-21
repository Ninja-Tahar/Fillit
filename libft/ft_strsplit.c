/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:42:58 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:29:27 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_count(char *str, char c)
{
	int		cnt;
	int		sign;

	cnt = 0;
	sign = 0;
	while (*str)
	{
		if (sign == 1 && *str == c)
			sign = 0;
		if (sign == 0 && *str != c)
		{
			cnt++;
			sign = 1;
		}
		str++;
	}
	return (cnt);
}

static	int		ft_len(char *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**p;
	int		nbrword;
	int		len;
	int		j;

	if (s == NULL)
		return (NULL);
	nbrword = ft_count((char *)s, c);
	j = 0;
	if (!(p = (char **)malloc((nbrword + 1) * sizeof(char *))))
		return (NULL);
	while (nbrword > 0)
	{
		while (*s == c)
			s++;
		len = ft_len((char *)s, c);
		p[j] = ft_strsub((char *)s, 0, len);
		s = s + len;
		nbrword--;
		j++;
	}
	p[j] = 0;
	return (p);
}
