/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:08:31 by amayer            #+#    #+#             */
/*   Updated: 2019/04/09 03:21:31 by amayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_tetri_topos(int i, t_map *map, int map_size, t_tetri *tetri)
{
	int block;
	int index;

	block = 0;
	while (block < 4)
	{
		index = (tetri->coords[block].y * map_size) + tetri->coords[block].x;
		(*map).str[i + index] = tetri->letter;
		block++;
	}
}

int		check_place(int i, t_map *map, int map_size, t_tetri *tetri)
{
	int block;
	int index;
	int x;
	int y;

	block = 0;
	while (block < 4)
	{
		index = (tetri->coords[block].y * map_size) + tetri->coords[block].x;
		if (i + index < map_size * map_size && (*map).str[i + index] != '.')
			return (-1);
		block++;
	}
	x = i % map_size;
	y = i / map_size;
	if ((x + tetri->w) >= map_size)
		return (-1);
	if ((y + tetri->h) >= map_size)
		return (-1);
	return (0);
}

int		place_tetri(int i, t_map *map, int map_size, t_tetri *tetri)
{
	while (i < map_size * map_size)
	{
		if (check_place(i, map, map_size, tetri) == 0)
		{
			place_tetri_topos(i, map, map_size, tetri);
			tetri->last_pos = i;
			return (0);
		}
		i++;
	}
	return (-1);
}

void	resolve(t_tetri *tetris, t_map *map, int i)
{
	while (i < map->total)
	{
		if (place_tetri(map->last_pos, map, map->map_size, &tetris[i]) == -1)
		{
			if (i == 0)
			{
				free(map->str);
				create_map(map, ++(map->map_size));
				map->last_pos = 0;
				i = 0;
			}
			else
			{
				remove_tetri(map, map->map_size, tetris[--i].letter);
				map->last_pos = tetris[i].last_pos + 1;
			}
		}
		else
		{
			map->last_pos = 0;
			i++;
		}
	}
}

void	init_resolve(t_tetri *tetris)
{
	int		i;
	int		map_size;
	t_map	map;
	int		total;

	total = 0;
	while (tetris[total].letter)
		total++;
	map.total = total;
	map.last_pos = 0;
	map_size = ft_square_sup(total * 4);
	create_map(&map, map_size);
	map.map_size = map_size;
	i = 0;
	resolve(tetris, &map, i);
	print_map(&map, map.map_size);
	free(map.str);
}
