/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 09:06:56 by amayer            #+#    #+#             */
/*   Updated: 2018/11/30 09:07:01 by amayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_nbr(char *str, int nb)
{
	ft_putstr(str);
	ft_putchar(' ');
	ft_putendl_nb(nb);
}