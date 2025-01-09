/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:31 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/09 12:19:50 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	first_mov(t_stack **stack_a, t_stack **stack_b)
{
	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
}


void	go_to_summit_a(t_stack *stack_a)
{
	while (stack_a->pos != 0)
	{
		if (stack_a->pos == 1)
		{
			do_sa(&stack_a);
		}
		else if (stack_a->is_above_med == 1)
		{
			do_ra(&stack_a);
		}
		else
		{
			do_rra(&stack_a);
		}
		assign_pos(stack_a);
	}
}

void	go_to_summit_b(t_stack *stack_b)
{
	while (stack_b->pos != 0)
	{
		if (stack_b->pos == 1)
		{
			do_sa(&stack_b);
		}
		else if (stack_b->is_above_med == 1)
		{
			do_ra(&stack_b);
		}
		else
		{
			do_rra(&stack_b);
		}
		assign_pos(stack_b);
	}
}

static t_stack	*get_cheapest(t_stack *stack_a)
{
	t_stack	*tmp;

	if (!stack_a)
		return (NULL);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->is_cheapest == 1)
			return (tmp);
		tmp = tmp->next;
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
	cheapest_node->is_cheapest = 1;
}

/*
void	fonction_test(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*target_a;

	assign_cost(*stack_a, *stack_b);
	
	tmp_a = get_cheapest(*stack_a);
	
	go_to_summit_a(tmp_a);
	go_to_summit_b(target_a);
	push_a_to_b(tmp_a, stack_b);
	
	//assign_cost(*stack_a, *stack_b);
}*/

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (!(cheapest->is_above_med) && !(cheapest->target->is_above_med))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			do_rr(stack_a, stack_b);
		assign_pos(*stack_a);
		assign_pos(*stack_b);
	}
	else if (cheapest->is_above_med && cheapest->target->is_above_med)

	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			do_rrr(stack_a, stack_b);
		assign_pos(*stack_a);
		assign_pos(*stack_b);
	}
	reorder_stacks(stack_a, cheapest, 'a');
	reorder_stacks(stack_b, cheapest->target, 'b');
	do_pb(stack_a, stack_b);
}

void	reorder_stacks(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->is_above_med)
				do_rra(stack);
			else
				do_ra(stack);
		}
		if (name == 'b')
		{
			if (top_node->is_above_med)
				do_rrb(stack);
			else
				do_rb(stack);
		}
	}
}

