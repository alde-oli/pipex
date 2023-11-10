/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:13:45 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 12:21:23 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

void	*ft_free_str_tab(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		strs[i] = ft_free(strs[i]);
		i++;
	}
	strs = ft_free(strs);
	return (NULL);
}
