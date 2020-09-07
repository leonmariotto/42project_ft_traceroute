/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:49:18 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 15:56:31 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_arrdup(void **arr, const size_t content_size)
{
	size_t	len;
	void	**a;
	size_t	i;

	if (!arr)
		return (NULL);
	len = ft_arrlen(arr);
	if (!(a = (void **)ft_memalloc(sizeof(void *) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!(a[i] = malloc(content_size)))
		{
			ft_arrfree(a);
			return (NULL);
		}
		ft_memcpy(a[i], arr[i], content_size);
		++i;
	}
	return (a);
}
