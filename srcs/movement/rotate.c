/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:28 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 15:32:59 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tail;

	tail = get_last(*stack);
	tail->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	tail->next->previous = tail;
	tail->next->next = NULL;
}

void	do_ra(t_stack	**stack_a, bool print)
{
	rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	do_rb(t_stack	**stack_b, bool print)
{
	rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	do_rr(t_stack	**stack_a, t_stack **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}
