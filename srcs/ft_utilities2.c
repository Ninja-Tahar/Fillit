/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:38:51 by mbenkara          #+#    #+#             */
/*   Updated: 2018/02/06 16:14:11 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*populate_piece(char *str, char value)
{
	t_pos	*mi;
	t_pos	*max;
	char	**pos;
	int		i;
	t_tetri	*tetri;

	mi = point_new(3, 3);
	max = point_new(0, 0);
	min_max(str, mi, max);
	pos = ft_memalloc(sizeof(char *) * (max->y - mi->y + 1));
	i = -1;
	while (++i < max->y - mi->y + 1)
	{
		pos[i] = ft_strnew(max->x - mi->x + 1);
		ft_strncpy(pos[i], str + (mi->x) + (i + mi->y) * 5, max->x - mi->x + 1);
	}
	tetri = new_tetri(pos, max->x - mi->x + 1, max->y - mi->y + 1, value);
	ft_memdel((void **)&mi);
	ft_memdel((void **)&max);
	return (tetri);
}

void		min_max(char *str, t_pos *min, t_pos *max)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

t_pos		*point_new(int x, int y)
{
	t_pos	*pos;

	pos = ft_memalloc(sizeof(t_pos));
	pos->x = x;
	pos->y = y;
	return (pos);
}
