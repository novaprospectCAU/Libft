/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:30 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:36 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	buf[1000];
	char	*p;

	i = 0;
	p = buf;
	if (src == NULL && len == 0)
		return (NULL);
	while (i < len)
	{
		*p++ = *(char *)src++;
		i++;
	}
	p -= i;
	i = 0;
	while (i < len)
	{
		*(char *)dst++ = *p++;
		i++;
	}
	return (dst - i);
}
