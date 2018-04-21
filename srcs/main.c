/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:39:51 by mbenkara          #+#    #+#             */
/*   Updated: 2018/02/05 18:21:02 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_last_piece(int fd)
{
	int		i;
	int		f;
	char	c;
	char	*s;

	i = 0;
	s = NULL;
	f = read(fd, &c, 1);
	if (f <= 0)
		return (0);
	if (f == 1)
	{
		s = (char *)malloc(sizeof(char) * 570);
		while (f != '\0')
		{
			s[i] = c;
			i++;
			f = read(fd, &c, 1);
		}
		s[i] = '\0';
	}
	if (check_last_piece2(s) == 1)
		return (0);
	return (1);
}

int		check_last_piece2(char *str)
{
	int		k;

	k = 0;
	while (str[k] != '\0')
	{
		if ((str[k] == '\n' && str[k + 2] == '\0')
				&& str[k + 1] == '\n')
			return (1);
		k++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	*lst;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if (check_last_piece(open(argv[1], O_RDONLY)) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	close((int)argv[1]);
	if ((lst = tetri_read(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solve(lst);
	print_map(map);
	frees_map(map);
	free_list(lst);
	return (0);
}
