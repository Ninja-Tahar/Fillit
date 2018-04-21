/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:36:24 by mbenkara          #+#    #+#             */
/*   Updated: 2018/02/06 16:13:27 by mbenkara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef	struct	s_map
{
	int			sz;
	char		**arr;
}				t_map;
typedef	struct	s_tetri
{
	int			wid;
	int			hei;
	char		**coord;
	char		val;
}				t_tetri;
typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

t_list			*tetri_read(int fd);
t_list			*free_list(t_list *list);
t_map			*new_map(int	sz);
void			print_map(t_map	*map);
void			frees_map(t_map	*map);
int				check_last_piece(int fd);
int				check_last_piece2(char *str);
void			min_max(char *str, t_pos *min, t_pos *max);
t_pos			*point_new(int x, int y);
t_tetri			*populate_piece(char *str, char value);
t_pos			*new_pos(int x, int y);
t_tetri			*new_tetri(char	**coord, int wid, int hei, char val);
void			free_tetri(t_tetri *tetri);
int				count_list(t_list *list);
t_map			*solve(t_list *lst);
int				get_size(int n);
int				map_solver(t_map *map, t_list *lst);
void			set_square(t_tetri *tetri, t_map *map, t_pos *pos, char c);
int				check_con(char *str);
int				check_cnts(char	*str, int count);
int				try_place(t_tetri *tetri, t_map	*map, int m, int n);
#endif
