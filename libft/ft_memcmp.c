/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:36:32 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:21:55 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (*((char*)s1) == *((char*)s2) && i < n - 1)
	{
		++s1;
		++s2;
		++i;
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
