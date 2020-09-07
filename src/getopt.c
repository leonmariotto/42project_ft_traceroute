/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 00:21:07 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/05 02:38:11 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static int		troute_help(void)
{
	ft_putendl("Usage: ft_troute [-vhIT] destination");
	ft_putendl("Usage: ft_troute -6 [-vhIT] destination");
	return (0);
}

static int		whicharg(char **args, int i)
{
	if (args[i][1] == '6')
		return ((g_troute->opt.ip6 = 1));
	else if (args[i][1] == 'v')
		return ((g_troute->opt.v = 1));
	else if (args[i][1] == 'I')
		return ((g_troute->opt.I = 1));
	else if (args[i][1] == 'T')
		return ((g_troute->opt.T = 1));
	else if (args[i][1] == 'h')
		return (troute_help());
	else
	{
		printf("ft_ping: Unknown opt : %c\n", args[i][1]);
		return (0);
	}
}

char			*ft_getopt(char **args)
{
	int i;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] != '-')
		{
			if (args[i + 1])
				return (NULL);
			return (args[i]);
		}
		if (!whicharg(args, i))
			return (NULL);
	}
	return (NULL);
}
