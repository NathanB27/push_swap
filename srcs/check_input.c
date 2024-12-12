/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:29:01 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/12 13:14:47 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



char	**clean_input(char *str)
{
	int	i;
	char **dest;

	i = 0;
	dest = ft_split(str, ' ');
	if (!dest)
		return(NULL);
	return (dest);
	
	// il faut free;
	
}
