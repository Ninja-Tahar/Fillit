/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:58:19 by mbenkara          #+#    #+#             */
/*   Updated: 2017/12/10 14:30:21 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	void	ft_nbr(char *str, int n, int len)
{
	len--;
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char			*ft_itoa(int n)
{
	char	*p;
	int		len;

	len = ft_len(n);
	p = ft_strnew(len);
	if (p == NULL)
		return (NULL);
	if (n == 0)
		p[0] = '0';
	if (n == -2147483648)
	{
		p[1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
		ft_nbr(p, n, len);
		return (p);
	}
	ft_nbr(p, n, len);
	return (p);
}
