/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:09 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:54 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_set;
	size_t	len_s1;
	size_t	len_new;
	size_t	m_flag;

	len_set = ft_strlen(set);
	len_s1 = ft_strlen(s1);
	len_new = 0;
	m_flag = 1;
	return (NULL);
}
