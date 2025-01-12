/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/12 13:16:42 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
*/

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**splited;
	bool	do_we_free;

	do_we_free = false;
	if (ac == 1)
		return (1);
	if (ac == 2 && av[1][0])
	{
		splited = ft_split(av[1], ' ');
		do_we_free = true;
	}
	else
		splited = av + 1;
	if (!splited || !splited[0] || !splited[0][0] ) /*check_errors(splited))*/
	{
		//ft_free_splited(splited, do_we_free);
		//ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = create_stack_a(splited);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	//ft_free_stack(&stack_a);
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
		{
			big_algo(stack_a, stack_b);
		}
	}
}

