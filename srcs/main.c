/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/19 17:00:23 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac,char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char **input;
	int	len;
	int	near;

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
		assign_index(stack_a, len + 1);
		first_mov(&stack_a, &stack_b);
		first_mov(&stack_a, &stack_b);
		near = get_value_nearest(stack_a->value, stack_b);
		ft_printf("the nearest value of the first el of stack_a %d\n", near);
		assign_cost(stack_a, stack_b);
		while (stack_a)
		{
			ft_printf("value : %d index : %d cost %d \n", stack_a->value, stack_a->index, stack_a->cost);
			stack_a = stack_a->next;
		}
	}
}
