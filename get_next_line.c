/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:28:57 by pierre            #+#    #+#             */
/*   Updated: 2024/04/26 22:42:49 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_list		*lst;
	int			ret;
	char		*str;
	static char	buffer[BUFFER_SIZE];

	lst = NULL;
	ret = 1;
	if (fd < 0)
		return (NULL);
	if (*buffer)
		lst = add_node(lst, ft_setter(buffer), buffer);
	while (!contains_nextline(buffer) && ret > 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
			lst = add_node(lst, ret, buffer);
	}
	str = get_string(lst);
	ft_lstclear(&lst);
	if (!*str)
		return (free(str), NULL);
	return (str);
}

t_list	*add_node(t_list *lst, int len, char *buffer)
{
	char	*str;
	t_list	*new;
	int		n;

	n = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (buffer[n])
	{
		str[n] = buffer[n];
		n++;
	}
	str[n] = '\0';
	new = ft_lstnew(str, len);
	ft_lstadd_back(&lst, new);
	return (lst);
}

int	contains_nextline(char *s)
{
	int	n;

	n = 0;
	while (s[n])
	{
		if (s[n] == '\n')
			return (1);
		n++;
	}
	return (0);
}

char	*ft_bzero(char *s, int len)
{
	int	n;

	n = 0;
	while (n < len)
	{
		s[n] = '\0';
		n++;
	}
	return (s);
}

int	ft_setter(char *buffer)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (buffer[n] != '\n')
	{
		buffer[n] = '\0';
		n++;
	}
	buffer[n] = '\0';
	n++;
	while (buffer[n])
	{
		buffer[i] = buffer[n];
		buffer[n] = '\0';
		i++;
		n++;
	}
	return (i);
}
