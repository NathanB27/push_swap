/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/08 11:17:55 by nboucher         ###   ########.fr       */
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
		assign_pos(stack_a);
		is_above_med(stack_a);
		
	}
}

