/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/16 14:27:43 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac,char **av)
{
	t_stack	*stack_a;
	int i;
	char **input;
	int	len;

	len = 0;
	i = 3;
	stack_a = NULL;
	input = parse(ac, av);
		if (!is_correct_input(input))
	{
		ft_printf("incorrect input\n");
		return (0);
	}
	ft_printf("is_correct_input\n");
	if (ac > 1)
	{
		stack_a = fill_stack_values(ac, input);
		//ft_printf("taille stack =  %d\n", get_stack_size(stack_a));
		//ft_printf("verif : %d\n", is_sorted(stack_a));
		len = get_stack_size(stack_a);
		assign_index(stack_a, len + 1);
		tiny_sort(&stack_a);
		while (i > 0)
		{
			ft_printf("stack_a->value : %d\n", stack_a->value);
			stack_a = stack_a->next;
			i --;
		}
	}
}

