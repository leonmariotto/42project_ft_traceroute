/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:35:56 by llenotre          #+#    #+#             */
/*   Updated: 2020/05/03 16:24:35 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_filename(const char *path)
{
	char *s;

	if (!(s = ft_strrchr(path, '/')))
		return (ft_strdup(path));
	if (!s || !s[1])
		return (ft_strnew(0));
	return (ft_strdup(s + 1));
}
