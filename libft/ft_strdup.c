/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 12:52:45 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:16:24 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = ft_strlen(s1);
	str1 = (char *)malloc((i + 1) * sizeof(char));
	if (str1 == NULL)
		return (NULL);
	str2 = str1;
	while (*s1)
	{
		*str1 = *s1;
		str1++;
		s1++;
	}
	*str1 = '\0';
	return (str2);
}
