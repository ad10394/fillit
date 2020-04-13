/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:17:23 by amayer            #+#    #+#             */
/*   Updated: 2019/04/09 03:18:39 by amayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_and_return(void *ptr, int r)
{
	free(ptr);
	return (r);
}

int		check_valid_tetriminos(char *str)
{
	int	block;
	int	connect;
	int	count;

	block = 0;
	connect = 0;
	count = 0;
	while (block < 20)
	{
		if (((block + 1) % 5 != 0 && str[block] != '#' && str[block] != '.')
			|| ((block + 1) % 5 == 0 && str[block] != '\n'))
			return (0);
		if (str[block] == '#')
		{
			count++;
			if (str[block + 1] == '#')
				connect += 2;
			if (block < 15 && str[block + 5] == '#')
				connect += 2;
		}
		block++;
	}
	if ((connect == 6 || connect == 8) && count == 4)
		return (1);
	return (0);
}

void	shift_tetri(int min_x, int min_y, t_tetri *tetri)
{
	int	block;
	int	max_x;
	int	max_y;

	max_x = 0;
	max_y = 0;
	block = 0;
	while (block < 4)
	{
		(*tetri).coords[block].x -= min_x;
		(*tetri).coords[block].y -= min_y;
		if ((*tetri).coords[block].x > max_x)
			max_x = (*tetri).coords[block].x;
		if ((*tetri).coords[block].y > max_y)
			max_y = (*tetri).coords[block].y;
		block++;
	}
	tetri->w = max_x;
	tetri->h = max_y;
}

void	get_coord(char *str, t_tetri *tetri)
{
	int	i;
	int block;
	int min_x;
	int min_y;

	i = 0;
	block = 0;
	min_x = 5;
	min_y = 5;
	while (str[i])
	{
		if (str[i] == '#')
		{
			(*tetri).coords[block].y = i / 5;
			(*tetri).coords[block].x = i % 5;
			if ((*tetri).coords[block].y < min_y)
				min_y = (*tetri).coords[block].y;
			if ((*tetri).coords[block].x < min_x)
				min_x = (*tetri).coords[block].x;
			block++;
		}
		i++;
	}
	shift_tetri(min_x, min_y, tetri);
}

int		readnload_tetris(int fd, t_tetri **tetris)
{
	int		i;
	int		ret;
	char	*str_tetri;
	int		final_bn;

	if (!(str_tetri = ft_strnew(21)))
		return (-1);
	i = 0;
	while ((ret = read(fd, str_tetri, READ_SIZE)) > 0)
	{
		if (check_valid_tetriminos(str_tetri) == 0
			|| ret != 20)
			return (free_and_return(str_tetri, -1));
		get_coord(str_tetri, &(*tetris)[i]);
		(*tetris)[i].letter = 65 + i;
		i++;
		final_bn = read(fd, str_tetri, 1);
	}
	if (ret == -1 || str_tetri[0] == '\0' || final_bn == 1)
	{
		free(str_tetri);
		return (-1);
	}
	free(str_tetri);
	return (1);
}
