/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtolst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmariott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:15:25 by lmariott          #+#    #+#             */
/*   Updated: 2019/05/30 20:57:06 by lmariott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_arrtolst(char **arr)
{
	t_list	*lst;
	int		i;

	i = 0;
	if (!arr || !*arr)
		return (NULL);
	lst = NULL;
	while (arr[i])
	{
		ft_lstpush(&lst, ft_lstnew_nodup(ft_strdup(arr[i]),
			ft_strlen(arr[i]) + 1));
		i++;
	}
	return (lst);
}
