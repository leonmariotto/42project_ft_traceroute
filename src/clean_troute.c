/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_troute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:32:00 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:37:20 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void				clean_troute(void)
{
	free(g_troute->dstaddr);
	free(g_troute->dstname);
	free(g_troute->fromaddr);
	free(g_troute->datagram);
	freeaddrinfo(g_troute->dst_ai);
	free(g_troute);
}
