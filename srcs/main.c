/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/13 10:21:30 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <string.h>

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;
	bool	need_free;

	need_free = false;
	split = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		need_free = true;
	}
	else if (ac > 2)
		split = av + 1;
	stack_a = create_stack_a(split);
	stack_b = NULL;
	if (is_correct_input(split))
		push_swap(&stack_a, &stack_b);
	if (need_free)
		free_input(split);
	free_stack(&stack_a, &stack_b);
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
	//else
		//ft_putstr_fd("error\n", 2);
}
