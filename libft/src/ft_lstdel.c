/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:23:06 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/21 17:38:03 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	if (alst && *alst && del)
	{
		list = *alst;
		while (list)
		{
			tmp = list->next;
			del(list->content, list->content_size);
			free(list);
			list = tmp;
		}
		*alst = NULL;
	}
}
