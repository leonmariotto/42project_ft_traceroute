/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:10:32 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:26:19 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"
#include <sys/time.h>

void							send_packet4(int ttl)
{
	void			*outpack;

	((struct ip *)g_troute->datagram)->ip_ttl = ttl;
	outpack = g_troute->datagram;
	gettimeofday(&g_troute->t_send, 0);
	sendto(g_troute->socket, outpack, IPHDRLEN + ICMPHDRLEN + DATALEN, 0
			, g_troute->dst_ai->ai_addr, g_troute->dst_ai->ai_addrlen);
}

/*
** send_packet6 :
** IPV6 -> j'utilise sendmsg, avec la structure cmsghdr je peux changer le
** hop limit, l'address source est spécifié dans le msghdr.
** On envoie l'icmp + data.
*/

static void						send_packet6end(struct msghdr *msghdr)
{
	gettimeofday(&g_troute->t_send, 0);
	if (sendmsg(g_troute->socket, msghdr, 0) < 0)
	{
		free(msghdr->msg_control);
		ft_putendl_fd("sendmsg return an error", 2);
		alarm(1);
		return ;
	}
	free(msghdr->msg_control);
}

void							send_packet6(int ttl)
{
	struct msghdr			msghdr;
	struct cmsghdr			*cmsghdr;
	struct iovec			iov[2];
	int						cmsglen;

	ft_bzero(&msghdr, sizeof(struct msghdr));
	msghdr.msg_name = (struct sockaddr_in6*)g_troute->dst_ai->ai_addr;
	msghdr.msg_namelen = sizeof(struct sockaddr_in6);
	ft_bzero(&iov, sizeof(iov));
	iov[0].iov_base = (uint8_t *)(g_troute->datagram + IPHDRLEN);
	iov[0].iov_len = ICMPHDRLEN + DATALEN;
	msghdr.msg_iov = iov;
	msghdr.msg_iovlen = 1;
	cmsglen = CMSG_SPACE(sizeof(int));
	if (!(msghdr.msg_control = (struct cmsghdr*)ft_memalloc(cmsglen)))
		return ;
	msghdr.msg_controllen = cmsglen;
	cmsghdr = CMSG_FIRSTHDR(&msghdr);
	cmsghdr->cmsg_level = IPPROTO_IPV6;
	cmsghdr->cmsg_type = IPV6_HOPLIMIT;
	cmsghdr->cmsg_len = CMSG_LEN(sizeof(int));
	*((int *)CMSG_DATA(cmsghdr)) = ttl;
	send_packet6end(&msghdr);
}

void							send_packet(int ttl)
{
	if (g_troute->opt.ip6)
		send_packet6(ttl);
	else
		send_packet4(ttl);
}
