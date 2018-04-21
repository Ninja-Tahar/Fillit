/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:07:23 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:13:05 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	j;
	unsigned char	*str;

	j = (unsigned char)c;
	str = (unsigned char *)b;
	while (len > 0)
	{
		*str = j;
		str++;
		len--;
	}
	return (b);
}
