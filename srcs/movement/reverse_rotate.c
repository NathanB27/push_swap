/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:14:28 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 15:33:55 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = get_last(*stack);
	tail->previous->next = NULL;
	tail->previous = NULL;
	tail->next = *stack;
	*stack = tail;
	tail->next->previous = tail;
}

void	do_rra(t_stack	**stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	do_rrb(t_stack	**stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	do_rrr(t_stack	**stack_a, t_stack **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
