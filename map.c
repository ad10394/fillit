/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:17:34 by amayer            #+#    #+#             */
/*   Updated: 2019/04/09 03:21:45 by amayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetri(t_map *map, int map_size, char letter)
{
	int i;

	i = 0;
	while (i < map_size * map_size)
	{
		if ((*map).str[i] == letter)
			(*map).str[i] = '.';
		i++;
	}
}

int		ft_square_sup(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i += 1;
	return (i);
}

void	print_map(t_map *map, int map_size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < map_size * map_size)
	{
		ft_putchar(map->str[i]);
		i++;
		count++;
		if (count >= map_size)
		{
			count = 0;
			ft_putchar('\n');
		}
	}
}

void	create_map(t_map *map, int map_size)
{
	int i;

	i = 0;
	(*map).str = malloc(sizeof(char) * map_size * map_size);
	while (i < map_size * map_size)
	{
		(*map).str[i] = '.';
		i++;
	}
}
