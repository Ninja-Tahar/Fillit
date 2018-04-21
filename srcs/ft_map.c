/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:37:07 by mbenkara          #+#    #+#             */
/*   Updated: 2018/02/06 16:13:43 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*new_map(int sz)
{
	t_map	*map;
	int		x;
	int		y;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->arr = (char **)ft_memalloc(sizeof(char *) * sz);
	map->sz = sz;
	x = -1;
	while (++x < sz)
	{
		map->arr[x] = ft_strnew(sz);
		y = -1;
		while (++y < sz)
			map->arr[x][y] = '.';
	}
	return (map);
}

void		print_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->sz)
	{
		ft_putstr(map->arr[i]);
		ft_putchar('\n');
	}
}

void		frees_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->sz)
		ft_memdel((void **)&(map->arr[i]));
	ft_memdel((void **)&(map->arr));
	ft_memdel((void **)&map);
}

int			try_place(t_tetri *tetri, t_map *map, int m, int n)
{
	int		x;
	int		y;

	x = -1;
	while (++x < tetri->wid)
	{
		y = -1;
		while (++y < tetri->hei)
			if (tetri->coord[y][x] == '#' && map->arr[y + n][x + m] != '.')
				return (0);
	}
	set_square(tetri, map, new_pos(m, n), tetri->val);
	return (1);
}

void		set_square(t_tetri *tetri, t_map *map, t_pos *pos, char c)
{
	int		q;
	int		w;

	q = -1;
	while (++q < tetri->wid)
	{
		w = -1;
		while (++w < tetri->hei)
			if (tetri->coord[w][q] == '#')
				map->arr[pos->y + w][pos->x + q] = c;
	}
	ft_memdel((void **)&pos);
}
