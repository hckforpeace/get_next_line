/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre <pierre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:57:46 by pierre            #+#    #+#             */
/*   Updated: 2024/04/30 21:29:11 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*get_line_mine(char *str);
char	*get_buffer_line(char *buffer, int fd);
char	*ft_strjoin(char *buffer, char *str);
char	*ft_strcat(char *dest, const char *src);
char	*reset_buffer(char	*buffer);

#endif
