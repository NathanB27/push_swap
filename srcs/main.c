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
	ft_printf("parse work well\n");
	if (!is_correct_input(input))
		return (0);
	if (ac > 1)
	{
		stack_a = fill_stack_values(input);
		ft_printf("fill stack_work\n");
		big_algo(&stack_a, &stack_b);
	} 

}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int	len;

	if (!stack_a)
		return ;
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

