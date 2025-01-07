/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/07 15:53:45 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac,char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char **input;
	int	len;
	len = 0;
	stack_b = NULL;
	stack_a = NULL;
	input = parse(ac, av);
	if (!is_correct_input(input))
		return (0);
	if (ac > 1)
	{
		stack_a = fill_stack_values(input);
		len = get_stack_size(stack_a);
		assign_index(stack_a, len);
		first_mov(&stack_a, &stack_b);
		first_mov(&stack_a, &stack_b);
		first_mov(&stack_a, &stack_b);
		cost_tobe_summit(stack_a);
		cost_tobe_summit(stack_b);
		assign_pos(stack_a);
		assign_pos(stack_b);
		len = get_stack_size(stack_b);
		//ft_printf("len stack b : %d\n", len);
		assign_index(stack_b, len);
		assign_cost(stack_a, stack_b);
		while (stack_a)
		{
		ft_printf("value : %d/ index : %d/ position %d/ is_above_med : %d cost : %d\n", stack_a->value, stack_a->index, stack_a->pos, stack_a->is_above_med, stack_a->cost);
			if(!stack_a->next)
				break;
			stack_a = stack_a->next;
		}
		/*
		while (stack_b)
		{
		ft_printf("value : %d/ index : %d/ position %d/ is_above_med : %d cost : %d\n", stack_b->value, stack_b->index, stack_b->pos, stack_b->is_above_med, stack_b->cost);
		stack_b = stack_b->next;
		}*/
		ft_printf("value nearest of %d in stack_b %d\n",stack_a->value, get_value_nearest(stack_a->value, stack_b));
	}
}
