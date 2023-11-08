/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:17:01 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 12:17:19 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

void	*ft_calloc(int size)
{
	void	*ptr;
	int		i;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
