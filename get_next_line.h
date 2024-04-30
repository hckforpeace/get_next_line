/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:28:46 by pierre            #+#    #+#             */
/*   Updated: 2024/04/23 11:29:49 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				len;
}	t_list;

char	*get_next_line(int fd);
int		contains_nextline(char *s);
char	*ft_bzero(char *s, int len);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content, int len);
void	ft_lstclear(t_list **lst);
t_list	*add_node(t_list *lst, int len, char *buffer);
char	*get_string(t_list *lst);
int		get_total_length(t_list *lst);
int		ft_setter(char *buffer);

#endif
