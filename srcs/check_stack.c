/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:13:24 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/17 14:00:01 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->next != NULL && (stack->value > stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}

