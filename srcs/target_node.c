/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:49:19 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/10 14:53:00 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*target;
	t_stack		*current_b;
	long int	target_index;

	while (stack_a)
	{
		target_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value && current_b->value > target_index)
			{
				target_index = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (target_index == LONG_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	target_node_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*target;
	t_stack		*current_a;
	long int	target_index;

	while (stack_b)
	{
		target_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value && current_a->value < target_index)
			{
				target_index = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (target_index == LONG_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}
