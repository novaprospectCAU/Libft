/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:44 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:42 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fs_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		if (i == 0 && *s != c)
			count++;
		else if (*(s + i) == c && *(s + i + 1) != c && *(s + i + 1) != '\0')
			count++;
		i++;
	}
	return (count + 1);
}

static void	fs_init_temp(char temp[], int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < 1000)
		{
			temp[i] = '\0';
			i++;
		}
	}
	else
		while (temp[i])
			temp[i++] = '\0';
}

static void	fs_clean_null(char **output, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(output[i]);
		i++;
	}
	free(output);
	output = NULL;
}

static void	fs_put(const char *s, char c, int count, char **output)
{
	int		i;
	int		output_idx;
	char	temp[1000];

	output_idx = 0;
	fs_init_temp(temp, 1);
	while (output_idx < count - 1)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			temp[i++] = *s++;
		i = 0;
		output[output_idx] = (char *)malloc(ft_strlen(temp) + 1);
		if (output[output_idx] == NULL)
			return (fs_clean_null(output, output_idx));
		//ft_strncpy(output[output_idx], temp, ft_strlen(temp));
		fs_init_temp(temp, 2);
		output_idx++;
	}
	output[count - 1] = (char *)malloc(1);
	output[count - 1] = NULL;
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**output;

	count = fs_count(s, c);
	output = (char **)malloc(count);
	if (output == NULL)
		return (NULL);
	fs_put(s, c, count, output);
	return (output);
}
