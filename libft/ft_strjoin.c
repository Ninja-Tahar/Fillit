/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:59:06 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:27:56 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = (char *)malloc((ft_strlen((char *)s1) +
				ft_strlen((char *)s2)) * sizeof(char));
	if (p == NULL)
		return (NULL);
	if (p)
	{
		ft_strcpy(p, s1);
		ft_strcat(p, s2);
	}
	return (p);
}
