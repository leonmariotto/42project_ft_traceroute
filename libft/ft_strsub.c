/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:33:53 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 17:09:25 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *buff;

	if (!s)
		return (NULL);
	if (!(buff = (char*)malloc(len + 1)))
		return (NULL);
	ft_strncpy(buff, s + start, len);
	buff[len] = '\0';
	return (buff);
}
