/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:53:13 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 17:09:38 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*buff;
	size_t	i;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
		++s;
	i = 0;
	if (*s)
	{
		i = ft_strlen(s);
		while (ft_isspace(s[i - 1]) && i - 1 > 0)
			--i;
	}
	if (!(buff = (char*)malloc(i + 1)))
		return (0);
	ft_strncpy(buff, s, i);
	buff[i] = '\0';
	return (buff);
}
