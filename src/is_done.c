/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:13:58 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:26:45 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int					is_done6(int c)
{
	struct icmp6_hdr *icmphdr;

	icmphdr = (struct icmp6_hdr*)(g_troute->rcv_buff);
	if (icmphdr->icmp6_type == ICMP6_ECHO_REPLY)
	{
		printf("%2d -> [%-*s] %.3f ms\nDestination reached\n", c,
				g_troute->opt.ip6 ? INET6_ADDRSTRLEN : INET_ADDRSTRLEN,
				g_troute->fromaddr,
				(double)(g_troute->t_diff.tv_sec * 1000) +
					(double)(g_troute->t_diff.tv_usec) / 1000);
		return (1);
	}
	return (0);
}

int					is_done4(int c)
{
	int type;

	type = (int)((struct icmp*)(g_troute->rcv_buff + IPHDRLEN))->icmp_type;
	if (type == ICMP_ECHOREPLY)
	{
		printf("%2d -> [%-*s] %.3f ms\nDestination reached\n", c,
				g_troute->opt.ip6 ? INET6_ADDRSTRLEN : INET_ADDRSTRLEN,
				g_troute->fromaddr,
				(double)(g_troute->t_diff.tv_sec * 1000) +
					(double)(g_troute->t_diff.tv_usec) / 1000);
		return (1);
	}
	return (0);
}

int					is_done(int c)
{
	if (g_troute->opt.ip6)
		return (is_done6(c));
	else
		return (is_done4(c));
}
