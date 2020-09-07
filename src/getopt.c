/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <lmariott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 00:21:07 by lmariott          #+#    #+#             */
/*   Updated: 2020/09/07 12:57:41 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

static int		troute_help(void)
{
	ft_putendl("Usage: ft_traceroute [-h] destination");
	ft_putendl("Usage: ft_traceroute -6 [-h] destination");
	return (0);
}

static int		whicharg(char **args, int i)
{
	if (args[i][1] == '6')
		return ((g_troute->opt.ip6 = 1));
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
