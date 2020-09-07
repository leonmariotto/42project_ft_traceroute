/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:43:00 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:27:25 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int					getip(char *hostname, struct addrinfo **result)
{
	struct addrinfo				*hints;

	if (!(hints = (struct addrinfo*)malloc(sizeof(struct addrinfo))))
		return (-1);
	hints->ai_family = (g_troute->opt.ip6 ? AF_INET6 : AF_INET);
	hints->ai_socktype = SOCK_DGRAM;
	hints->ai_flags = 0;
	hints->ai_protocol = 0;
	if (getaddrinfo(hostname, 0, hints, result) != 0)
	{
		ft_putendl_fd("Could not resolv hostname", 2);
		free(hints);
		return (-1);
	}
	free(hints);
	return (0);
}

int					resolv_addrs(char *dsthost)
{
	if (getip(dsthost, &g_troute->dst_ai) < 0)
		return (-1);
	if (!g_troute->opt.ip6)
		inet_ntop(AF_INET,
			(const void *)&((struct sockaddr_in*)g_troute->
				dst_ai->ai_addr)->sin_addr,
			g_troute->dstaddr, 35);
	else
		inet_ntop(AF_INET6,
			(const void *)&((struct sockaddr_in6*)g_troute->
				dst_ai->ai_addr)->sin6_addr,
			g_troute->dstaddr, 35);
	return (0);
}
