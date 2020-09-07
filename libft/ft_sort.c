/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:59:32 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:22:56 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort(void **arr, size_t size, int (*f)(void*, void*))
{
	size_t	i;
	size_t	j;
	void	*k;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (f(arr[i], arr[j]) > 0)
			{
				k = arr[i];
				arr[i] = arr[j];
				arr[j] = k;
			}
			++j;
		}
		++i;
	}
}
