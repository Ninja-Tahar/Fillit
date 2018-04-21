/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:05:13 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:28:19 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		nombr_esp1(char const *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
			i++;
		else
			return (i);
		s++;
	}
	return (0);
}

static	int		nombr_esp2(char *s)
{
	int		len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
			len--;
		else
			return (len + 1);
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*p;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	j = 0;
	i = nombr_esp1((char *)s);
	k = nombr_esp2((char *)s);
	j = k - i;
	p = (char *)malloc((j + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	k = 0;
	p = ft_strncpy(p, &s[i], j + 1);
	p[j] = '\0';
	return (p);
}
