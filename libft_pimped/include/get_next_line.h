/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:00 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/11 16:02:28 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

// prototyoe of function in get_next_line

char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*add_in_buffer(int fd, char *buffer);
char	*get_the_line(char *buffer);
char	*del_line_buffer(char *buffer);

// prototype of function utils...

size_t		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);

#endif
