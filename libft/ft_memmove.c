/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:38:59 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:14:22 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (ds > sr)
	{
		ds = ds + len - 1;
		sr = sr + len - 1;
		while (len > 0)
		{
			*ds-- = *sr--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*ds++ = *sr++;
			len--;
		}
	}
	return (dst);
}
