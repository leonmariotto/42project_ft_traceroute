/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:11:11 by pemora            #+#    #+#             */
/*   Updated: 2019/04/28 21:56:08 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmpcase(char c1, char c2)
{
	if (ft_islower(c1) && ft_isupper(c2))
		return ((unsigned char)(c1 - 32) - (unsigned char)c2);
	else if (ft_isupper(c1) && ft_islower(c2))
		return ((unsigned char)(c1 + 32) - (unsigned char)c2);
	else
		return ((unsigned char)c1 - (unsigned char)c2);
}

int			ft_strcmpcase(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && (*(s2 + i) && *(s1 + i)))
		i++;
	return (cmpcase(*(s1 + i), *(s2 + i)));
}
