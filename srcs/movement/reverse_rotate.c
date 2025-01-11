/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:14:28 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/11 16:42:00 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;

	tail = get_bottom(*stack);
	tail->previous->next = NULL;
	tail->previous = NULL;
	tail->next = *stack;
	*stack = tail;
	tail->next->previous = tail;

}

void	do_rra(t_stack	**stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack	**stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack	**stack_a, t_stack **stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
	ft_printf("rrr\n");
}

