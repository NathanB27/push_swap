/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:49:19 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 13:36:23 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*target;
	t_stack		*current;
	long int	target_pos;

	while (stack_a)
	{
		target_pos = LONG_MIN;
		current = stack_b;
		while (current)
		{
			if (current->value < stack_a->value && current->value > target_pos)
			{
				target_pos = current->value;
				target = current;
			}
			current = current->next;
		}
		if (target_pos == LONG_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	target_node_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*target;
	t_stack		*current;
	long int	target_pos;

	while (stack_b)
	{
		target_pos = LONG_MAX;
		current = stack_a;
		while (current)
		{
			if (current->value > stack_b->value && current->value < target_pos)
			{
				target_pos = current->value;
				target = current;
			}
			current = current->next;
		}
		if (target_pos == LONG_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}
