/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:38:03 by mbenkara          #+#    #+#             */
/*   Updated: 2018/02/06 16:14:05 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*tetri_read(int fd)
{
	char	alpha;
	char	*buffer;
	int		cnt;
	t_list	*lst;
	t_tetri	*tetri;

	lst = NULL;
	alpha = 'A';
	buffer = ft_strnew(21);
	while ((cnt = read(fd, buffer, 21)) >= 20)
	{
		if ((tetri = populate_piece(buffer, alpha++)) == NULL
				|| check_cnts(buffer, cnt) != 0)
		{
			ft_memdel((void **)&buffer);
			return (free_list(lst));
		}
		ft_lstadd(&lst, ft_lstnew(tetri, sizeof(t_tetri)));
		ft_memdel((void **)&tetri);
	}
	ft_memdel((void **)&buffer);
	if (cnt != 0)
		return (free_list(lst));
	ft_lstrev(&lst);
	return (lst);
}

int			check_con(char *str)
{
	int		block;
	int		i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int			check_cnts(char *str, int count)
{
	int		i;
	int		blocks;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (1);
	if (!check_con(str))
		return (1);
	return (0);
}

t_list		*free_list(t_list *list)
{
	t_tetri	*tetri;
	t_list	*next;

	while (list)
	{
		tetri = (t_tetri *)list->content;
		next = list->next;
		free_tetri(tetri);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
