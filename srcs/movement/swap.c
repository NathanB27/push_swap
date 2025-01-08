/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:13:26 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/08 10:57:27 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
//sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
//ss : sa and sb at the same time.

#include "push_swap.h"
/*
void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->pos;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}
*/

static void	swap(t_stack *stack)
{
	int	tmp;
	
	if (stack == NULL || stack->next == NULL)
		return;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->pos;
	stack->pos = stack->next->pos;
	stack->next->pos = tmp;
		
}

void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}
