/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:09:10 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:21:44 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buff;
	size_t	i;

	if (!(buff = malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		*((char*)buff + i) = 0;
		++i;
	}
	return (buff);
}
