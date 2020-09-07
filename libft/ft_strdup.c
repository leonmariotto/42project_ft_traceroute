/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:58:29 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 17:02:06 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*buff;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1) + 1;
	if (!(buff = (char*)malloc(i)))
		return (NULL);
	ft_strcpy(buff, s1);
	return (buff);
}
