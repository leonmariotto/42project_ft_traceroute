/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:35:37 by llenotre          #+#    #+#             */
/*   Updated: 2018/11/13 20:22:07 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (src < dst)
	{
		i = 0;
		while (i < len)
		{
			*((char*)dst + (len - i - 1)) = *((char*)src + (len - i - 1));
			++i;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
