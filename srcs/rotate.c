/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:00:28 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/16 15:00:32 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack= (*stack)->next;
	tail = get_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_stack	**stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	do_rb(t_stack	**stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	do_rr(t_stack	**stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
	ft_printf("rr\n");
}
