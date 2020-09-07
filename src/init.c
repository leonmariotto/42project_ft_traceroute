/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:45:44 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 09:38:21 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int			init_mytroute(void)
{
	if (!(g_troute = (t_troute*)ft_memalloc(sizeof(t_troute)))
			|| !(g_troute->datagram = ft_memalloc(IPHDRLEN + ICMPHDRLEN
					+ DATALEN))
			|| !(g_troute->dstaddr = ft_strnew(INET6_ADDRSTRLEN))
			|| !(g_troute->fromaddr = ft_strnew(INET6_ADDRSTRLEN)))
		return (1);
	return (0);
}

int			init_troute(char *dsthost)
{
	if (!(g_troute->dstname = ft_strdup(dsthost)))
		return (1);
	if (resolv_addrs(dsthost))
		return (1);
	if (fill_content())
		return (1);
	if (g_troute->opt.ip6)
	{
		if (fill_hdrs6() < 0)
			return (-1);
		if (request_socket6() < 0)
			return (-1);
	}
	else
	{
		if (fill_hdrs4() < 0)
			return (-1);
		if (request_socket4() < 0)
			return (-1);
	}
	return (0);
}
