/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:31:36 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/11 18:43:44 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, unsigned int factor)
{
	unsigned int	i;
	int				j;

	if (factor == 0)
		return (TRUE);
	i = 0;
	j = 1;
	while (i < factor)
	{
		j *= n;
		++i;
	}
	return (j);
}
