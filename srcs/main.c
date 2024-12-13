/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/13 10:44:57 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac,char **av)
{
	t_stack	*stack_a;
	int i;
	char **input;

	i = 1;
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
		while (i < ac)
		{
			ft_printf("%d\n", stack_a->value);
			stack_a = stack_a->next;
			i++;
		}
	}
}

