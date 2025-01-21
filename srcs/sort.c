/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:31 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/21 17:39:58 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reorder_stacks(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->is_above_med)
				do_rra(stack, true);
			else
				do_ra(stack, true);
		}
		if (name == 'b')
		{
			if (top_node->is_above_med)
				do_rrb(stack, true);
			else
				do_rb(stack, true);
		}
	}
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (!(cheapest->is_above_med) && !(cheapest->target->is_above_med))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			do_rr(stack_a, stack_b, true);
		set_position(*stack_a);
		set_position(*stack_b);
	}
	else if ((cheapest->is_above_med) && (cheapest->target->is_above_med))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			do_rrr(stack_a, stack_b, true);
		set_position(*stack_a);
		set_position(*stack_b);
	}
	reorder_stacks(stack_a, cheapest, 'a');
	reorder_stacks(stack_b, cheapest->target, 'b');
	do_pb(stack_a, stack_b, true);
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	reorder_stacks(stack_a, (*stack_b)->target, 'a');
	do_pa(stack_a, stack_b, true);
}

void	order_a(t_stack **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a)->value)
	{
		set_position(*stack_a);
		if ((find_min(*stack_a)->is_above_med))
			do_rra(stack_a, true);
		else
			do_ra(stack_a, true);
	}
}
