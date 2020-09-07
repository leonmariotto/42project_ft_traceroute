/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:00:52 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/31 17:45:41 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_arrinsert(void **arr, void *element)
{
	size_t	len;
	void	**a;

	len = (arr ? ft_arrlen(arr) : 0);
	if (!(a = (void **)malloc(sizeof(void *) * (len + 2))))
		return (NULL);
	if (arr)
		ft_memcpy(a, arr, sizeof(void *) * (len + 1));
	a[len] = element;
	a[len + 1] = NULL;
	if (arr)
		free((void *)arr);
	return (a);
}
