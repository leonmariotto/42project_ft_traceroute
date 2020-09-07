/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:12:04 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:12:33 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int					is_mine6(void)
{
	struct icmp6_hdr *icmphdr;

	icmphdr = (struct icmp6_hdr*)(g_troute->rcv_buff);
	if (icmphdr->icmp6_type == ICMP6_ECHO_REPLY)
	{
		if (icmphdr->icmp6_id !=
		((struct icmp6_hdr*)(g_troute->datagram + IPHDRLEN))->icmp6_id)
			return (0);
		return (1);
	}
	else if (icmphdr->icmp6_type < 128)
	{
		if ((icmphdr + 6)->icmp6_id !=
		((struct icmp6_hdr*)(g_troute->datagram + IPHDRLEN))->icmp6_id)
			return (0);
		return (1);
	}
	return (0);
}

int					is_mine4(void)
{
	if (((struct icmp*)
			(g_troute->rcv_buff + IPHDRLEN))->icmp_type == ICMP_ECHOREPLY)
	{
		if (((struct icmp*)(g_troute->rcv_buff + IPHDRLEN))->icmp_id
				== ((struct icmp*)(g_troute->datagram + IPHDRLEN))->icmp_id)
			return (1);
	}
	else
	{
		if (((struct icmp*)(g_troute->rcv_buff + 48))->icmp_id
				== ((struct icmp*)(g_troute->datagram + IPHDRLEN))->icmp_id)
			return (1);
	}
	return (0);
}

int					is_mine(void)
{
	if (g_troute->opt.ip6)
		return (is_mine6());
	else
		return (is_mine4());
}
