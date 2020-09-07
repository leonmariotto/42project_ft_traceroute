/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:23:23 by llenotre          #+#    #+#             */
/*   Updated: 2019/01/30 17:07:15 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(const size_t n, va_list args)
{
	va_list		a;
	size_t		i;
	size_t		j;
	const char	*s;

	va_copy(a, args);
	i = 0;
	j = 0;
	while (i < n)
	{
		if ((s = va_arg(a, const char*)))
			j += ft_strlen(s);
		++i;
	}
	va_end(a);
	return (j);
}

char			*ft_strnjoin(const size_t n, ...)
{
	va_list		args;
	size_t		len;
	size_t		i;
	char		*buffer;
	const char	*c;

	va_start(args, n);
	if (!(len = get_length(n, args)))
		return (NULL);
	if (!(buffer = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		if ((c = va_arg(args, const char*)))
		{
			ft_strcpy(buffer + i, c);
			i += ft_strlen(c);
		}
	}
	buffer[i] = '\0';
	va_end(args);
	return (buffer);
}
