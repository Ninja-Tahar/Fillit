/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:43:19 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:23:53 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*p;

	p = (char *)malloc((size + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size + 1);
	return (p);
}
