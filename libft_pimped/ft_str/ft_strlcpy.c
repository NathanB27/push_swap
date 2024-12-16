/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:46 by nboucher          #+#    #+#             */
/*   Updated: 2024/11/14 15:16:20 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i ++;
	if (siz == 0)
		return (i);
	while (src[j] && j < siz - 1)
	{
		dst[j] = src[j];
		j ++;
	}
	if (siz > 0)
		dst[j] = '\0';
	return (i);
}
