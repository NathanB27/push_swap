/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/06 16:08:25 by nboucher         ###   ########.fr       */
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
		ft_printf("succes of both first mov\n");
		assign_cost(stack_a, stack_b);
		ft_printf("succes of both first mov\n");
	}
}
