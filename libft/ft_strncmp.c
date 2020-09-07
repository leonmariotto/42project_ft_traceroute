/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:47:10 by llenotre          #+#    #+#             */
/*   Updated: 2019/06/21 15:55:48 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2 || !n)
		return (0);
	i = 0;
	while (*s1 && *s2 && *s1 == *s2 && i < n - 1)
	{
		++s1;
		++s2;
		++i;
	}
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}
