/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:08 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:32:53 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	mflag;

	result = 0;
	mflag = 1;
	while (*nptr && (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || \
			*nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			mflag = -1;
		nptr++;
	}
	while (*nptr && (*nptr > 47 && *nptr < 58))
	{
		result *= 10;
		result += (*nptr - '0');
		nptr++;
	}
	return (mflag * result);
}
