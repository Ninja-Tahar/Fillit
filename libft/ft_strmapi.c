/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 17:01:07 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:26:23 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	char			*pp;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	pp = p;
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		*p = f(i, s[i]);
		i++;
		p++;
	}
	*p = '\0';
	return (pp);
}
