/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:39:20 by mbenkara          #+#    #+#             */
/*   Updated: 2018/02/06 16:14:22 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos		*new_pos(int x, int y)
{
	t_pos	*pos;

	pos = ft_memalloc(sizeof(t_pos));
	pos->x = x;
	pos->y = y;
	return (pos);
}

t_tetri		*new_tetri(char **coord, int wid, int hei, char val)
{
	t_tetri	*tetri;

	tetri = ft_memalloc(sizeof(t_tetri));
	tetri->coord = coord;
	tetri->val = val;
	tetri->hei = hei;
	tetri->wid = wid;
	return (tetri);
}

void		free_tetri(t_tetri *tetri)
{
	int		i;

	i = -1;
	while (++i < tetri->hei)
		ft_memdel((void **)(&(tetri->coord[i])));
	ft_memdel((void **)(&(tetri->coord)));
	ft_memdel((void **)&tetri);
}

int			get_size(int n)
{
	int		sz;

	sz = 2;
	while (sz * sz < n)
		sz++;
	return (sz);
}
