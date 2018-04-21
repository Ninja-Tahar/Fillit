/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:39:54 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:18:21 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size > 0 && size <= dst_len)
		return (size + src_len);
	i = 0;
	len = dst_len + src_len;
	while (*dst)
		dst++;
	if (size > dst_len)
	{
		i = size - dst_len - 1;
		while (*src && i > 0)
		{
			*dst++ = *src++;
			i--;
		}
		*dst = '\0';
		return (len);
	}
	return (src_len);
}
