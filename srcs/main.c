/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:28:43 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 15:35:31 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdbool.h>

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
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
			do_sa(stack_a, true);
		else if (len == 3)
			tiny_sort(stack_a);
		else
		{
			algo(stack_a, stack_b);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;
	bool	need_free;

	need_free = false;
	if (ac == 1)
		return (1);
	if (ac == 2 && av[1][0])
	{
		input = ft_split(av[1], ' ');
		need_free = true;
	}
	else
		input = av + 1;
	if (!input || !input[0] || !input[0][0] || !is_correct_input(input))
	{
		free_input(input, need_free);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = create_stack_a(input);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
}
