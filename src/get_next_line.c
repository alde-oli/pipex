/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:55:49 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/03 22:08:01 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_gen_line(char *buf, int fd)
{
	int		count;
	char	*tmp;

	if (!buf)
		buf = ft_calloc(1 * sizeof(char));
	tmp = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp || !buf)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
		{
			tmp = ft_free(tmp);
			buf = ft_free(buf);
			return (NULL);
		}
		tmp[count] = '\0';
		buf = ft_strjoin_gnl(buf, tmp);
		if (ft_find_nl(tmp) != -1)
			break ;
	}
	tmp = ft_free(tmp);
	return (buf);
}

static char	*ft_crop_line(char *buf)
{
	int		i;
	char	*str;

	if (buf[0] == '\0')
		return (NULL);
	i = ft_find_nl(buf);
	if (i == -1)
		i = ft_strlen(buf);
	str = ft_strndup(buf, i);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_get_cropped(char *buf)
{
	int		i;
	int		j;
	char	*new_buf;

	if (!buf)
		return (NULL);
	i = ft_find_nl(buf);
	if (i == -1)
		return (ft_free(buf));
	new_buf = ft_calloc((ft_strlen(buf + i) + 1) * sizeof(char));
	if (!new_buf)
		return (ft_free(buf));
	j = 0;
	while (buf[++i])
	{
		new_buf[j++] = buf[i];
	}
	new_buf[j] = '\0';
	buf = ft_free(buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	static t_file	f;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (fd != f.fd)
	{
		if (f.buf)
			f.buf = ft_free(f.buf);
		f.fd = fd;
	}
	f.buf = ft_gen_line(f.buf, fd);
	if (!f.buf)
		return (NULL);
	line = ft_crop_line(f.buf);
	f.buf = ft_get_cropped(f.buf);
	return (line);
}
