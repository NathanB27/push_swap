/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:11:50 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/11 14:32:48 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	cost_tobe_summit(t_stack *stack)
{
	int	len;
	int	i;
	t_stack	*tmp;

	tmp = stack;
	len = get_stack_size(tmp);
	i = 0;
	is_above_med(stack);
	tmp = stack;
	while (tmp && (i < len / 2))
	{
		tmp->cost = i;
		tmp = tmp->next;
		i++;
	}
	if (len % 2 == 1)
	{
		tmp->cost = i;
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmp->cost = i;
		tmp = tmp->next;
		i--;
	}
}
*/
int	get_min(t_stack **stack)
{
	int	min;
 
	min = (*stack)->value;
	while (*stack)
	{
		if (min > (*stack)->value)
			min = (*stack)->value;
		*stack = (*stack)->next;
	}
	return (min);
}
/*
static int	get_max(t_stack **stack)
{
	int	max;
 
	max = (*stack)->value;
	while (*stack)
	{
		if (max < (*stack)->value)
			max = (*stack)->value;
		*stack = (*stack)->next;
	}
	return (max);
}
*/

t_stack	*get_ptr(int value, t_stack *stack_b)
{
	t_stack	*dest;
	
	dest = NULL;
	while (stack_b != NULL)
	{
		if (stack_b->value == value)
			return (stack_b);
		stack_b = stack_b->next;
	}
	return (stack_b);
}

void	assign_target(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		(*stack_a)->target = find_min(*stack_b);
		*stack_a = (*stack_a)->next;
	}
}
/*
void	assign_cost(t_stack	*stack_a, t_stack *stack_b)
{
	
	assign_target(&stack_a, &stack_b);
	
	cost_tobe_summit(stack_a);
	cost_tobe_summit(stack_b);
	while (stack_a)
	{
		stack_a->cost += stack_a->target->cost;
		stack_a = stack_a->next;
	}
}
*/
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
	int	va_under;
	int	va_above;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	ft_printf("before loop \n");
	while (stack_a)
	{
		ft_printf("before biggest  \n");
		va_under = biggest(stack_a->pos, stack_a->target->pos);
		va_above = biggest(len_a - stack_a->pos, len_b - stack_a->target->pos);
		ft_printf(" func biggest work \n");
		stack_a->cost = stack_a->pos;
		if (stack_a->is_above_med)
			stack_a->cost = len_a - (stack_a->pos);
		if (!(stack_a->target->is_above_med))
			stack_a->cost += (stack_a->target->pos);
		else
			stack_a->cost += len_b - (stack_a->target->pos);
		if (stack_a->is_above_med && stack_a->target->is_above_med)
			stack_a->cost = va_above;
		else if (!(stack_a->is_above_med) && !(stack_a->target->is_above_med))
			stack_a->cost = va_under;
		stack_a = stack_a->next;
	}
}

