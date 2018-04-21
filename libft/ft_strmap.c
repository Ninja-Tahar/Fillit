/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:26:32 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:26:11 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	char	*pp;

	if (s == NULL)
		return (NULL);
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	pp = p;
	if (p == NULL)
		return (NULL);
	while (*s)
	{
		*p = f(*s);
		s++;
		p++;
	}
	*p = '\0';
	return (pp);
}
