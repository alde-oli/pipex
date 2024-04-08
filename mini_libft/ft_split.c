/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:38:38 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 13:59:09 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

static int	ft_str_nbr(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char	*ft_strncpy(char const *s, int i, char c)
{
	char	*str;
	int		j;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	str = ft_calloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[i] && s[i] != c)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = ft_calloc(sizeof(char *) * (ft_str_nbr(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j++] = ft_strncpy(s, i, c);
			if (tab[j - 1] == NULL)
				return (ft_free_str_tab(tab));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = (NULL);
	return (tab);
}
