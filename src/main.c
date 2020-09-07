/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 01:17:31 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:31:50 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int			main(int ac, char **av)
{
	char		*host;

	(void)ac;
	if (init_mytroute())
		return (1);
	if (!(host = ft_getopt(&av[1])))
		return (1);
	if (init_troute(host))
		return (1);
	printf("traceroute to %s (%s)\n\n", g_troute->dstaddr, g_troute->dstname);
	if (trouteloop())
	{
		clean_troute();
		return (1);
	}
	clean_troute();
	return (0);
}
