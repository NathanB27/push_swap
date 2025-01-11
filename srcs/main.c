/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/11 16:33:35 by nboucher         ###   ########.fr       */
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
		stack_a = create_stack_a(input);
		stack_b = NULL;
		push_swap(&stack_a, &stack_b);
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	len;

	if (!stack_a)
	{
		return ;	
	}
	len = get_stack_size(*stack_a);
	if (!is_sorted(*stack_a))
	{
		if (len == 2)
			do_sa(stack_a);
		else if (len == 3)
			tiny_sort(stack_a);
		else
			big_algo(stack_a, stack_b);
	}
}

