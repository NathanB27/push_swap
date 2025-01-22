/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:28 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/22 13:51:12 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
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

void	do_rb(t_stack **stack_b, bool print)
{
	if (!stack_b || !*stack_b)
		return ;
	rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	do_rr(t_stack	**stack_a, t_stack **stack_b, bool print)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}
