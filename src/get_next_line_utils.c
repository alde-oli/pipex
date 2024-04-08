/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:32:52 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/03 22:08:22 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		j;
	int		i;
	int		len;
	char	*dest;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = ft_calloc(len * sizeof(char));
	if (!dest)
		return (ft_free(s1));
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	ft_free(s1);
	return (dest);
}

char	*ft_strndup(char *src, int i)
{
	int		j;
	char	*dest;

	j = 0;
	dest = ft_calloc((i + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	while (j <= i && src[j])
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
