/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icmp6_checksum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 06:40:19 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:10:03 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

/*
** Build IPv6 ICMP pseudo-header and call checksum
** function (Section 8.1 of RFC 2460).
** 1 - Copy source IP address into buf (128 bits)
** 2 - Copy destination IP address into buf (128 bits)
** 3 - Copy Upper Layer Packet length into buf (32 bits).
** 4 - Should not be greater than 65535 (i.e., 2 bytes).
** 5 - Copy zero field to buf (24 bits)
** 6 - Copy next header field to buf (8 bits)
** 7 - Copy ICMPv6 type to buf (8 bits)
** 8 - Copy ICMPv6 code to buf (8 bits)
** 9 - Copy ICMPv6 ID to buf (16 bits)
** 10 - Copy ICMPv6 sequence number to buff (16 bits)
** 11 - Copy ICMPv6 checksum to buf (16 bits)
** 12 - Copy ICMPv6 payload to buf
** 13 - Pad to the next 16-bit boundary
*/

void			chksumpart1(struct ip6_hdr iphdr, char **ptr,
				int *chksumlen, int payloadlen)
{
	ft_memcpy(*ptr, &iphdr.ip6_src.s6_addr, sizeof(iphdr.ip6_src.s6_addr));
	*ptr += sizeof(iphdr.ip6_src);
	chksumlen += sizeof(iphdr.ip6_src);
	ft_memcpy(*ptr, &iphdr.ip6_dst.s6_addr, sizeof(iphdr.ip6_dst.s6_addr));
	*ptr += sizeof(iphdr.ip6_dst.s6_addr);
	*chksumlen += sizeof(iphdr.ip6_dst.s6_addr);
	**ptr = 0;
	(*ptr)++;
	**ptr = 0;
	(*ptr)++;
	**ptr = (ICMPHDRLEN + payloadlen) / 256;
	(*ptr)++;
	**ptr = (ICMPHDRLEN + payloadlen) % 256;
	(*ptr)++;
	*chksumlen += 4;
	**ptr = 0;
	(*ptr)++;
	**ptr = 0;
	(*ptr)++;
	**ptr = 0;
	(*ptr)++;
	*chksumlen += 3;
	ft_memcpy(*ptr, &iphdr.ip6_nxt, sizeof(iphdr.ip6_nxt));
	*ptr += sizeof(iphdr.ip6_nxt);
	*chksumlen += sizeof(iphdr.ip6_nxt);
}

void			chksumpart2(struct icmp6_hdr icmp6hdr, char **ptr,
				int *chksumlen)
{
	ft_memcpy(*ptr, &icmp6hdr.icmp6_type, sizeof(icmp6hdr.icmp6_type));
	*ptr += sizeof(icmp6hdr.icmp6_type);
	*chksumlen += sizeof(icmp6hdr.icmp6_type);
	ft_memcpy(*ptr, &icmp6hdr.icmp6_code, sizeof(icmp6hdr.icmp6_code));
	*ptr += sizeof(icmp6hdr.icmp6_code);
	*chksumlen += sizeof(icmp6hdr.icmp6_code);
	ft_memcpy(*ptr, &icmp6hdr.icmp6_id, sizeof(icmp6hdr.icmp6_id));
	*ptr += sizeof(icmp6hdr.icmp6_id);
	*chksumlen += sizeof(icmp6hdr.icmp6_id);
	ft_memcpy(*ptr, &icmp6hdr.icmp6_seq, sizeof(icmp6hdr.icmp6_seq));
	*ptr += sizeof(icmp6hdr.icmp6_seq);
	*chksumlen += sizeof(icmp6hdr.icmp6_seq);
	**ptr = 0;
	(*ptr)++;
	**ptr = 0;
	(*ptr)++;
	*chksumlen += 2;
}

uint16_t		icmp6_checksum(struct ip6_hdr iphdr,
				struct icmp6_hdr icmp6hdr, uint8_t *payload, int payloadlen)
{
	char		buf[IP_MAXPACKET];
	char		*ptr;
	int			chksumlen;
	int			i;

	chksumlen = 0;
	ptr = &buf[0];
	chksumpart1(iphdr, &ptr, &chksumlen, payloadlen);
	chksumpart2(icmp6hdr, &ptr, &chksumlen);
	ft_memcpy(ptr, payload, (payloadlen - 4) * sizeof(uint8_t));
	ptr += payloadlen;
	chksumlen += payloadlen;
	i = -1;
	while (++i < payloadlen % 2)
	{
		*ptr = 0;
		ptr += 1;
		chksumlen += 1;
		ptr++;
	}
	return (checksum((uint16_t*)buf, chksumlen));
}
