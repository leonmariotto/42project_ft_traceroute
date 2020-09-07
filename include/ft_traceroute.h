/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traceroute.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:19:59 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:34:02 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRACEROUTE_H
# define FT_TRACEROUTE_H

# include "libft.h"
# include <stdio.h>
# include <netdb.h>
# include <unistd.h>
# include <netinet/ip.h>
# include <netinet/ip6.h>
# include <netinet/icmp6.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/socket.h>
# include <arpa/inet.h>

typedef struct			s_option
{
	char		ip6;
	char		h;
	char		v;
	char		I;
	char		T;
}						t_option;

typedef struct			s_troute
{
	struct addrinfo					*dst_ai;
	void							*probe;
	int								socket;
	char							*dstname;
	char							*dstaddr;
	char							*fromaddr;
	void							*datagram;
	char							rcv_buff[4096];
	struct timeval					t_send;
	struct timeval					t_diff;
	t_option						opt;
}						t_troute;

char				*ft_getopt(char **args);

int					getip(char *hostname, struct addrinfo **result);
int					resolv_addrs(char *dsthost);

int					init_mytroute(void);
int					init_troute(char *dsthost);

int						request_socket6(void);
int						request_socket4(void);

int					fill_content(void);

int						fill_hdrs6(void);
int						fill_hdrs4(void);
unsigned short			checksum(unsigned short *addr, int len);

uint16_t		icmp6_checksum(struct ip6_hdr iphdr,
				struct icmp6_hdr icmp6hdr, uint8_t *payload, int payloadlen);

void							send_packet(int ttl);
int					is_mine(void);

int					trouteloop(void);
int					is_done(int c);
void				clean_troute(void);

# ifndef MYTROUTE
#  define MYTROUTE

t_troute 			*g_troute;

# endif

# define IPHDRLEN				20
# define ICMPHDRLEN				24
# define DATALEN				40

# define PACKETLEN				84
# define PACKET6LEN				44


#endif
