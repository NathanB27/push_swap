/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:16:48 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 15:28:58 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	tmp->previous = NULL;
	if (!*dst)
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->previous = tmp;
		*dst = tmp;
	}
}

void	do_pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	push(stack_a, stack_b);
	if (print)
		ft_printf("pa\n");
}

void	do_pb(t_stack **stack_a, t_stack **stack_b, bool print)
{
	push(stack_b, stack_a);
	if (print)
		ft_printf("pb\n");
}
