/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:01:10 by llenotre          #+#    #+#             */
/*   Updated: 2019/06/08 01:52:51 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int	n;
	int	neg;

	if (!str)
		return (0);
	while (*str && (*str == ' ' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\f' || *str == '\v'))
		++str;
	neg = (*str == '-');
	if (*str == '+' || *str == '-')
		++str;
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		++str;
	}
	return (neg ? -n : n);
}
