/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:45:25 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/16 11:26:32 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft_pimped/include/get_next_line.h"

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
	stack_a = create_stack_a(input);
	return (stack_a);
}

bool	is_end_line(char c)
{
	if (c == '\n' || c == '\0')
		return (true);
	return (false);
}

void	free_checker(t_stack **a, t_stack **b, char **s)
{
	t_stack	*tmp;

	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
	}
	if (b)
	{
		while (*b)
		{
			tmp = (*b)->next;
			free(*b);
			*b = tmp;
		}
	}
	if (s && *s)
		free(*s);
	get_next_line(-1);
}

