/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsimanau <lsimanau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:04:41 by lmariott          #+#    #+#             */
/*   Updated: 2019/06/19 20:02:28 by lsimanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_lsttoarr(t_list *lst)
{
	char	**arr;
	int		i;

	if (!lst)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_lstsize(lst) + 1))))
		return (NULL);
	i = 0;
	while (lst && lst->content)
	{
		if (!(arr[i++] = ft_strdup((char *)lst->content)))
		{
			arr[i] = NULL;
			ft_arrfree((void**)arr);
			return (NULL);
		}
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}
