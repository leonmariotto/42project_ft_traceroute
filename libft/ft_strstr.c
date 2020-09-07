/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:56:18 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 17:09:11 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (!haystack || !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		while (1)
		{
			if (needle[i] == '\0')
				return ((char*)haystack);
			if (haystack[i] != needle[i])
				break ;
			++i;
		}
		++haystack;
	}
	return (0);
}
