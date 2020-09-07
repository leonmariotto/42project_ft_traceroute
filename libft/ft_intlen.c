/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llenotre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:07:52 by llenotre          #+#    #+#             */
/*   Updated: 2018/12/19 16:07:52 by llenotre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(const int n)
{
	if (n < 0)
		return ((n < -9 ? ft_intlen(-(n / 10)) + 1 : 1) + 1);
	else
		return (n > 9 ? ft_intlen(n / 10) + 1 : 1);
}
