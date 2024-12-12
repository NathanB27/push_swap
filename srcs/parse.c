/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:05:30 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/12 16:13:13 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char *str)
{
	int	i;
	char **dest;
	int	*input;
	int	j;

	j = 0;
	dest = ft_split(str, ' ');
	if (!dest)
	{
		free(dest);
		return (0);
	}
	while (dest[j])
		j ++;
	input = (int *)malloc(sizeof(int) * j + 1);
	if (!input)
		return (0);
	input[j + 1] = '\0';
	i = 0;
	while (dest[i - 1])
	{
		input[i] = ft_atoi(dest[i]);
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	free(dest);
	free(input);
	return (1);
}
