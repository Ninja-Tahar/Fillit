/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:22:30 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:14:05 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	unsigned char	j;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	j = (unsigned char)c;
	while (n > 0)
	{
		*ds = *sr;
		if (*sr == j)
			return (ds + 1);
		ds++;
		sr++;
		n--;
	}
	return (NULL);
}
