/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:57:21 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/12 14:16:42 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	tiny_sort(t_stack **stack_a)
{
	t_stack	*highest;

	highest = find_max(*stack_a);
	if (*stack_a == highest)
		do_ra(stack_a);
	else if ((*stack_a)->next == highest)
		do_rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		do_sa(stack_a);
	
}

void	init_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	set_position(stack_a);
	set_position(stack_b);
	target_node_a(stack_a, stack_b);
	calcul_cost(stack_a, stack_b);
	define_cheapest(stack_a);
}

void	big_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack;

	len_stack = get_stack_size(*stack_a);
	if (len_stack-- > 3 && !is_sorted(*stack_a))
		do_pb(stack_a, stack_b);
	if (len_stack-- > 3 && !is_sorted(*stack_a))
		do_pb(stack_a, stack_b);
	while (len_stack-- > 3)
	{
		init_stack_a(*stack_a, *stack_b);	
		push_a_to_b(stack_a, stack_b);
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		set_position(*stack_a);
		set_position(*stack_b);
		target_node_b(*stack_a, *stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	set_position(*stack_a);
	order_a(stack_a);
}

