/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:12:31 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 12:21:43 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_calloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	j = 0;
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
