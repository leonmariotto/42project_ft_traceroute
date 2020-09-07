/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:40:17 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/05 12:51:09 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int					fill_content(void)
{
	int		j;
	int		offset;

	if (g_troute->opt.ip6)
		offset = ICMPHDRLEN;
	else
		offset = IPHDRLEN + ICMPHDRLEN;
	j = -1;
	while (++j < DATALEN)
		((char*)(g_troute->datagram + offset))[j] = 16 + j;
	return (0);
}
