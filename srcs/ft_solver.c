/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:37:31 by mbenkara          #+#    #+#             */
/*   Updated: 2018/02/06 16:13:54 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_list(t_list *list)
{
	int		i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_map		*solve(t_list *lst)
{
	t_map	*map;
	int		sz;

	sz = get_size(count_list(lst) * 4);
	map = new_map(sz);
	while (!map_solver(map, lst))
	{
		sz++;
		frees_map(map);
		map = new_map(sz);
	}
	return (map);
}

int			map_solver(t_map *map, t_list *lst)
{
	int		x;
	int		y;
	t_tetri	*tetri;

	if (lst == NULL)
		return (1);
	y = 0;
	tetri = (t_tetri *)(lst->content);
	while (y < map->sz - tetri->hei + 1)
	{
		x = 0;
		while (x < map->sz - tetri->wid + 1)
		{
			if (try_place(tetri, map, x, y))
			{
				if (map_solver(map, lst->next))
					return (1);
				else
					set_square(tetri, map, point_new(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}
