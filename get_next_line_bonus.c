/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:14:55 by pierre            #+#    #+#             */
/*   Updated: 2024/04/30 21:20:35 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*str;

	if (read(fd, 0, 0))
		return (NULL);
	buffer[fd] = get_buffer_line(buffer[fd], fd);
	str = get_line(buffer[fd]);
	buffer[fd] = reset_buffer(buffer[fd]);
	return (str);
}

char	*get_buffer_line(char *buffer, int fd)
{
	char	*str;
	int		ret;

	ret = 1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	while (ft_strchr(buffer, '\n') == NULL)
	{
		ret = read(fd, str, BUFFER_SIZE);
		str[ret] = '\0';
		if (ret == 0)
			break ;
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*str;
	int		n;

	n = 0;
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	while (buffer[n])
	{
		str[n] = buffer[n];
		n++;
		if (buffer[n - 1] == '\n')
			break ;
	}
	str[n] = '\0';
	return (str);
}

char	*reset_buffer(char	*buffer)
{
	char	*new;
	int		n;

	n = 0;
	if (!buffer || !ft_strchr(buffer, '\n'))
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[n] != '\n')
		n++;
	n++;
	if (ft_strlen(&buffer[n]) == 0)
	{
		free(buffer);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(&buffer[n]) + 1));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	ft_strcat(new, &buffer[n]);
	free(buffer);
	return (new);
}
