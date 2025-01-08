/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:57:21 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/08 10:46:15 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_value(t_stack *stack)
{
	int	value;

	value = stack->value;
	while (stack)
	{
		if ( stack->value > value)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}

void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_value(*stack);
	if ((*stack)->value == highest)
		do_ra(stack);
	else if ((*stack)->next->value == highest)
		do_rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		do_sa(stack);
}
