/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:26:21 by byelee            #+#    #+#             */
/*   Updated: 2022/11/15 14:26:33 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*fs_clear_all(t_list *move, t_list *start, void (*del)(void *))
{
	t_list	*tmp;

	tmp = start;
	while (start != move)
	{
		tmp = start -> next;
		if (tmp == move)
			tmp = NULL;
		ft_lstdelone(start, del);
		start = tmp;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_node;
	t_list	*moving;
	size_t	flag;

	moving = NULL;
	flag = 1;
	start_node = NULL;
	while (lst != NULL)
	{
		moving = (t_list *)malloc(sizeof(t_list));
		if (moving == NULL)
			return (fs_clear_all(moving, start_node, del));
		if (flag)
		{
			start_node = moving;
			flag = 0;
		}
		moving -> content = lst -> content;
		moving -> next = lst -> next;
		f(moving -> content);
		moving = NULL;
		lst = lst -> next;
	}
	return (start_node);
}
