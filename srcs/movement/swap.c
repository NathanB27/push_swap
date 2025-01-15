/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:13:26 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 15:33:13 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	*stack = (*stack)->next;
	(*stack)->previous->previous = *stack;
	(*stack)->previous->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->previous = (*stack)->previous;
	(*stack)->next = (*stack)->previous;
	(*stack)->previous = NULL;
}

void	do_sa(t_stack **stack_a, bool print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	do_sb(t_stack **stack_b, bool print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
