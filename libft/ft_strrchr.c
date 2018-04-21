/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:23:44 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:19:03 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*b;
	char	*j;

	b = (char *)s;
	j = NULL;
	while (*b)
	{
		if (*b == (char)c)
			j = b;
		b++;
	}
	if ((char)c == '\0')
		return (b);
	return (j);
}
