/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouteloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:58:13 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:25:16 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

/*
** On envoie les paquets 1 par 1.
** Un timeoute de 3 seconde est fixé par paquet.
*/

int								time_diff(void)
{
	struct timeval		now;

	gettimeofday(&now, NULL);
	g_troute->t_diff.tv_sec = now.tv_sec - g_troute->t_send.tv_sec;
	g_troute->t_diff.tv_usec = now.tv_usec - g_troute->t_send.tv_usec;
	return (1);
}

int								rcv_(void)
{
	struct sockaddr					src_addr;
	socklen_t						srcaddrsize;
	int								r;
	fd_set							fds;
	struct timeval					wait;

	FD_ZERO(&fds);
	FD_SET(g_troute->socket, &fds);
	wait.tv_sec = 3;
	wait.tv_usec = 0;
	srcaddrsize = (g_troute->opt.ip6 ? INET6_ADDRSTRLEN : INET_ADDRSTRLEN);
	if (!(r = 0) && select(g_troute->socket + 1, &fds, NULL, NULL, &wait) > 0)
	{
		r = recvfrom(g_troute->socket, g_troute->rcv_buff, 2048,
				0, &src_addr, &srcaddrsize);
		if (time_diff() && !g_troute->opt.ip6)
			inet_ntop(AF_INET,
				(const void *)&((struct sockaddr_in*)&src_addr)->sin_addr,
				g_troute->fromaddr, INET_ADDRSTRLEN);
		else
			inet_ntop(AF_INET6,
				(const void *)&((struct sockaddr_in6*)&src_addr)->sin6_addr,
				g_troute->fromaddr, INET6_ADDRSTRLEN);
	}
	return (r);
}

void							print_result(int c)
{
	if (*g_troute->fromaddr && is_mine())
	{
		printf("%2d -> [%-*s] %.3f ms\n", c,
				g_troute->opt.ip6 ? INET6_ADDRSTRLEN : INET_ADDRSTRLEN,
				g_troute->fromaddr,
				(double)(g_troute->t_diff.tv_sec * 1000) +
					(double)(g_troute->t_diff.tv_usec) / 1000);
		ft_bzero(g_troute->fromaddr, INET6_ADDRSTRLEN);
	}
	else
	{
		printf("%2d -> *\n", c);
		ft_bzero(g_troute->fromaddr, INET6_ADDRSTRLEN);
	}
}

int								trouteloop(void)
{
	int c;

	c = 0;
	while (c < 30)
	{
		send_packet(++c);
		if (rcv_())
		{
			if (is_mine() && is_done(c))
				return (0);
		}
		print_result(c);
	}
	return (0);
}
