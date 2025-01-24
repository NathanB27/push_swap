/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:13:24 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/24 15:22:14 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static bool is_zero(const char *s)
{
    if (!s || !*s)
        return (false);
    if (*s == '+' || *s == '-')
        s++;
    while (*s)
    {
        if (*s != '0')
            return (false);
        s++;
    }
    return (true);
}

bool double_zero(char **str)
{
    int i;
	int	j;

    i = 0;
	j = 0;
    while (str && str[i])
    {
        if (is_zero(str[i]))
        {
            j = 0;
            while (str && str[j])
            {
                if (i != j && is_zero(str[j]))
					return (true);
                j++;
            }
        }
        i++;
    }
    return (false);
}
