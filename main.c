/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <amayer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:06:59 by amayer            #+#    #+#             */
/*   Updated: 2019/04/09 06:01:20 by amayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_tetri	*tetris;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	tetris = ft_memalloc(sizeof(t_tetri) * 27);
	fd = open(argv[1], O_RDONLY);
	if (readnload_tetris(fd, &tetris) != 1)
	{
		ft_putendl("error");
		free(tetris);
		return (0);
	}
	init_resolve(tetris);
	free(tetris);
	return (0);
}
