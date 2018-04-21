/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:04:56 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:20:26 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n - 1 > 0)
	{
		s1++;
		s2++;
		n--;
		if (!*s1 && !*s2)
			return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
