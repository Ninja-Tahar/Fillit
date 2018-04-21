/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:00:30 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:18:47 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*b;

	b = (char *)s;
	while (*b)
	{
		if (*b == (char)c)
			return (b);
		b++;
	}
	if ((char)c == '\0')
		return (b);
	return (NULL);
}
