/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:45:25 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/21 14:34:15 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*init_input_and_stack(int ac, char **av)
{
	bool	need_free;
	char	**input;
	t_stack	*stack_a;

	need_free = false;
	if (ac == 1)
		return (NULL);
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
		return (NULL);
	}
	stack_a = create_stack_a(input, need_free);
	return (stack_a);
}

bool	is_end_line(char c)
{
	if (c == '\n' || c == '\0')
		return (true);
	return (false);
}

void	free_checker(t_stack **stack_a, t_stack **stack_b, char **str)
{
	t_stack	*tmp;

	if (stack_a)
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
	}
	if (stack_b)
	{
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
	}
	if (str && *str)
		free(*str);
	get_next_line(-1);
}
