/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/09 10:59:40 by nboucher         ###   ########.fr       */
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
		assign_pos(stack_b);
		
		first_mov(&stack_a, &stack_b);
		first_mov(&stack_a, &stack_b);
		first_mov(&stack_a, &stack_b);
		
		assign_pos(stack_b);
		assign_pos(stack_a);
		ft_printf("----------------------------------------------------------\n");

		fonction_test(&stack_a, &stack_b);
		/*while (stack_a)
		{
			ft_printf("value : %d position : %d above median ? : %d \n", stack_a->value, stack_a->pos, stack_a->is_above_med);
			stack_a = stack_a->next;
		}
		ft_printf("----------------------------------------------------------\n");
		while (stack_b)
		{
			ft_printf("value : %d position : %d above median ? : %d \n", stack_b->value, stack_b->pos, stack_b->is_above_med);
			stack_b = stack_b->next;	
		}
		
		while (stack_a)
		{
			ft_printf("value : %d position : %d above median : %d cost : %d \n", stack_a->value, stack_a->pos, stack_a->is_above_med, stack_a->cost);
			stack_a = stack_a->next;
		}
		ft_printf("----------------------------------------------------------\n");
		while (stack_b)
		{
			ft_printf("value : %d position : %d above median : %d cost : %d \n", stack_b->value, stack_b->pos, stack_b->is_above_med, stack_b->cost);
			stack_b = stack_b->next;
		}
		*/
	} 
}

