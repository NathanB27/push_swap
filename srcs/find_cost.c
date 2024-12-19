/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:11:50 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/19 17:02:54 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost_summit(t_stack *stack)
{
	int	len;
	int	i;
	t_stack	*tmp;

	tmp = stack;
	len = get_stack_size(tmp);
	i = 0;
	while (i <= (len / 2)) 
	{
		tmp->cost = i;
		tmp = tmp->next;
		tmp->is_above_med = 1;
		i++;
	}
	if (len % 2 == 1)
		i--;
	else 
		i-=2;
	while (tmp)
	{
		tmp->cost = i;
		tmp = tmp->next;
		i--;
	}
}
int	get_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (min > stack->value)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_value_nearest(int	value, t_stack *stack_b)
{
	t_stack	*tmp;
	int		nearest;
	tmp = stack_b;

	nearest = get_min(stack_b);
	while (tmp)
	{
		if (tmp->value > value)
			tmp = tmp->next;
		else if (tmp->value < value)
		{
			if (tmp->value > nearest)
				nearest = tmp->value;
			if (nearest == tmp->value - 1)
				return (nearest);
			tmp = tmp->next;
		}
	}
	return (nearest);
}


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

void	assign_cost(t_stack	*stack_a, t_stack *stack_b)
{
	int	nearest;
	t_stack	*tmp_b;
	
	get_cost_summit(stack_a);
	get_cost_summit(stack_b);
	nearest = 0;
	ft_printf("test\n");
	while (stack_a)
	{
		tmp_b = stack_b;
		nearest = get_value_nearest(stack_a->value, stack_b);
		//ft_printf("testo\n");
		stack_a->target = get_ptr(nearest, stack_b);
		//ft_printf("testo value target : %p\n", get_ptr(nearest, stack_b));
		stack_a->cost += stack_a->target->cost + 1;
		//ft_printf("testo\n");
		stack_a = stack_a->next;
	}
}

