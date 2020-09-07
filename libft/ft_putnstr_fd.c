/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemora <pemora@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 03:10:43 by pemora            #+#    #+#             */
/*   Updated: 2018/12/26 18:02:03 by pemora           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(int fd, int n, ...)
{
	va_list	str;

	va_start(str, n);
	while (n--)
		ft_putstr_fd(va_arg(str, char*), fd);
	va_end(str);
}
