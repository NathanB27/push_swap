/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:31 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/12 13:04:11 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_mov(t_stack **stack_a, t_stack **stack_b)
{
	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
}

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	define_cheapest(t_stack *stack)
{
	long int	cheapest;
	t_stack		*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest)
		{
			cheapest = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	
	cheapest = get_cheapest(*stack_a);
	if (!(cheapest->is_above_med) && !(cheapest->target->is_above_med))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			do_rr(stack_a, stack_b);
		set_position(*stack_a);
		set_position(*stack_b);
	}
	else if ((cheapest->is_above_med) && (cheapest->target->is_above_med))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			do_rrr(stack_a, stack_b);
		set_position(*stack_a);
		set_position(*stack_b);
	}
	reorder_stacks(stack_a, cheapest, 'a');
	reorder_stacks(stack_b, cheapest->target, 'b');
	do_pb(stack_a, stack_b);
}
/*
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			rr(stack_a, stack_b, true);
		set_node_index(*stack_a);
		set_node_index(*stack_b);
	}
	else if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			rrr(stack_a, stack_b, true);
		set_node_index(*stack_a);
		set_node_index(*stack_b);
	}
	reorder_stacks(stack_a, cheapest, 'a');
	reorder_stacks(stack_b, cheapest->target, 'b');
	pb(stack_a, stack_b, true);
}

*/
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	reorder_stacks(stack_a, (*stack_b)->target, 'a');
	do_pa(stack_a, stack_b);

}

void	reorder_stacks(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if ((top_node->is_above_med))
				do_rra(stack);
			else
				do_ra(stack);
		}
		if (name == 'b')
		{
			if ((top_node->is_above_med))
				do_rrb(stack);
			else
				do_rb(stack);
		}
	}
}

t_stack	*find_min(t_stack *stack)
{
	long int	min;
	t_stack		*tmp;

	if (!stack)
		return (NULL);
	tmp = NULL;
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp);
}

t_stack	*find_max(t_stack *stack)
{
	long int	max;
	t_stack		*tmp;

	if (!stack)
		return (NULL);
	tmp = NULL;
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp);
}


void	order_a(t_stack **stack_a)
{
	while ((*stack_a)->value != find_min(*stack_a)->value)
	{
		set_position(*stack_a);
		if ((find_min(*stack_a)->is_above_med))
			do_rra(stack_a);
		else
			do_ra(stack_a);
	}
}
