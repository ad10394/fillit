/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:24:44 by amayer            #+#    #+#             */
/*   Updated: 2019/04/09 06:02:07 by amayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define READ_SIZE 20

# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_map{
	int		map_size;
	int		total;
	int		last_pos;
	char	*str;
}				t_map;

typedef struct	s_coords{
	int	x;
	int	y;
}				t_coords;

typedef struct	s_tetri{
	t_coords	coords[4];
	char		letter;
	int			last_pos;
	int			w;
	int			h;
}				t_tetri;

int				free_and_return(void *ptr, int r);
int				check_valid_tetriminos(char *str);
int				ft_square_sup(int nb);
void			print_map(t_map *map, int map_size);
void			create_map(t_map *map, int map_size);
void			remove_tetri(t_map *map, int map_size, char letter);
void			place_tetri_topos(int i, t_map *map,
					int map_size, t_tetri *tetri);
int				check_place(int i, t_map *map, int map_size, t_tetri *tetri);
int				place_tetri(int i, t_map *map, int map_size, t_tetri *tetri);
void			resolve(t_tetri *tetris, t_map *map, int i);
void			init_resolve(t_tetri *tetris);
void			shift_tetri(int min_x, int min_y, t_tetri *tetri);
void			get_coord(char *str, t_tetri *tetri);
int				readnload_tetris(int fd, t_tetri **tetris);

#endif
