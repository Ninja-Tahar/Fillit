/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:13:08 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:19:20 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *str1;
	char *str2;

	str1 = (char *)big;
	str2 = (char *)little;
	if (*little == '\0')
		return ((char *)big);
	while (*big && *little)
	{
		if (*big == *little)
		{
			str1 = (char *)big + 1;
			str2 = (char *)little + 1;
			while (*str1 && *str2 && *str1 == *str2)
			{
				++str1;
				++str2;
			}
		}
		if (*str2 == '\0')
			return ((char *)(big));
		big++;
	}
	return (NULL);
}
