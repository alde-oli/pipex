/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:41:31 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 11:44:13 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
