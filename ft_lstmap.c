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

static int	fs_count_node(t_list *moving)
{
	int	count;

	count = 0;
	while (moving != NULL)
	{
		count++;
		moving = moving -> next;
	}
	return (count);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*moving;
	t_list	*strict;
	int		count;

	moving = lst;
	strict = lst;
	count = fs_count_node(moving);
	f(moving -> content);
	del(moving -> content);
	return (NULL);
}
