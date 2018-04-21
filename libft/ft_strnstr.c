/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:04:50 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:19:49 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;

	if (!*little)
		return ((char *)big);
	while (*big && len > 0)
	{
		if (*big == *little)
		{
			str1 = (char *)big + 1;
			str2 = (char *)little + 1;
			i = len - 1;
			while (*str1 && str2 && i-- > 0 && *str1 == *str2)
			{
				str1++;
				str2++;
			}
			if (!*str2)
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (NULL);
}
