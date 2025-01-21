/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:13:24 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/21 18:05:12 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->next && (stack->value > stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}


bool double_zero(char **str)
{
    int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str && str[i])
	{
		if (!ft_strncmp(str[i], "0", ft_strlen(str[i])))
		{
			while (*str && str[j])
			{
				if (!ft_strncmp(str[j], "-0", ft_strlen(str[j]))
					|| !ft_strncmp(str[j], "+0", ft_strlen(str[j])))
					return (true);
				j++;
			}
		}
		i++;
	}
	return (false);
}

