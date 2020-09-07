/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_merge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:19:05 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/22 21:00:21 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_path_merge(const char *p1, const char *p2)
{
	char *str;
	char *path;

	if (p1 == NULL || p2 == NULL)
		return (NULL);
	if (*p1 == '\0')
		return (ft_strdup(p2));
	if (*p2 == '\0')
		return (ft_strdup(p1));
	if (p1[ft_strlen(p1) - 1] != '/')
	{
		if (!(str = ft_strjoin(p1, "/")))
			return (NULL);
		path = ft_strjoin(str, p2);
		free((void*)str);
	}
	else
		path = ft_strjoin(p1, p2);
	return (path);
}
