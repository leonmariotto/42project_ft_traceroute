/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemora <pemora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:52:37 by pemora            #+#    #+#             */
/*   Updated: 2018/11/10 16:26:52 by pemora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		len;
	char	swap;

	i = -1;
	len = ft_strlen(s) - 1;
	while (++i <= len / 2)
	{
		swap = *(s + i);
		*(s + i) = *(s + (len - i));
		*(s + (len - i)) = swap;
	}
	return (s);
}
