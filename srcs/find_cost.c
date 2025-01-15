/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:11:50 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 13:42:49 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	calcul_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;
	int	cost_down;
	int	cost_up;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	while (stack_a)
	{
		cost_down = biggest(stack_a->pos, stack_a->target->pos);
		cost_up = biggest(len_a - stack_a->pos, len_b - stack_a->target->pos);
		stack_a->cost = stack_a->pos;
		if (stack_a->is_above_med)
			stack_a->cost = len_a - (stack_a->pos);
		if (!(stack_a->target->is_above_med))
			stack_a->cost += (stack_a->target->pos);
		else
			stack_a->cost += len_b - (stack_a->target->pos);
		if (stack_a->is_above_med && stack_a->target->is_above_med)
			stack_a->cost = cost_up;
		else if (!(stack_a->is_above_med) && !(stack_a->target->is_above_med))
			stack_a->cost = cost_down;
		stack_a = stack_a->next;
	}
}
