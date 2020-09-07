/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:43:11 by llenotre          #+#    #+#             */
/*   Updated: 2019/02/07 13:43:12 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *buff;

	if (!s || !n)
		return (NULL);
	if (!(buff = ft_strnew(n)))
		return (NULL);
	return (ft_strncpy(buff, s, n));
}
