/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvassago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:46:40 by cvassago          #+#    #+#             */
/*   Updated: 2019/09/23 13:54:42 by cvassago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdel_fun(void *content, size_t content_size)
{
	free(content);
	content = NULL;
	content_size = 0;
}

static void	ft_lstnext(t_list **last, t_list *lst)
{
	t_list	*tmp;

	if (last && *last && lst)
	{
		tmp = *last;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = lst;
	}
	else if (last && !(*last) && lst)
		*last = lst;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	head = NULL;
	while (lst)
	{
		if (!(tmp = f(lst)))
		{
			if (head)
				ft_lstdel(&head, &ft_lstdel_fun);
			return (NULL);
		}
		if (!head)
		{
			head = tmp;
			new = head;
		}
		else
			ft_lstnext(&new, tmp);
		lst = lst->next;
	}
	return (head);
}
