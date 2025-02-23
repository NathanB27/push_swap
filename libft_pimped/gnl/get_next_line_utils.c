/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:16:17 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/21 16:57:28 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(count * size);
	if (!dest)
		return (NULL);
	while (i < count * size)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_strjoin_free_1(char *s1, char *s2)
{
	int		i;
	char	*dest;
	int		j;

	i = 0;
	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	dest = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (s1 && s1[++i])
		dest[i] = s1[i];
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	dest[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (dest);
}
