/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:13:26 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 16:23:21 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_arrremove(void **arr, const size_t index)
{
	if (!arr)
		return (NULL);
	free((void *)arr[index]);
	ft_memmove(arr + index, arr + index + 1,
		sizeof(void *) * (ft_arrlen(arr) - index));
	return (arr);
}
