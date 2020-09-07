/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_socket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:33:56 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:28:48 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

/*
** Ouverture du socket raw
** need root privilege
** Setsockopt pour que le noyau n'ajoute pas de header IP, falcultatif
** avec IPPROTO_ICMP
** Optval non-zero for enable boolean option. (man)
*/

static int				socketerror(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (-1);
}

int						request_socket6(void)
{
	if ((g_troute->socket = socket(AF_INET6, SOCK_RAW, IPPROTO_ICMPV6)) < 0)
		return (socketerror("socket raw v6 return an error\nAre you root ?\n"));
	return (0);
}

int						request_socket4(void)
{
	int										optval;
	struct timeval							tv;

	if ((g_troute->socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
		return (socketerror("socket raw return an error\nAre you root ?\n"));
	optval = 1;
	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (setsockopt(g_troute->socket, IPPROTO_IP, IP_HDRINCL,
		&optval, sizeof(int)) || setsockopt(g_troute->socket, IPPROTO_IP,
		SO_RCVTIMEO, (void*)&tv, sizeof(struct timeval)))
		return (socketerror("setsockopt return an error"));
	return (0);
}
