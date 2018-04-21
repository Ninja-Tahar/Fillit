/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:11:12 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:17:39 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ds;

	ds = dst;
	while (*src && len > 0)
	{
		*dst = *src;
		len--;
		dst++;
		src++;
	}
	while (len > 0)
	{
		*dst = '\0';
		len--;
		dst++;
	}
	return (ds);
}
