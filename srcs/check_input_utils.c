/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:44:53 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 13:27:12 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sign(char c)
{
	if (c == '+')
		return (true);
	if (c == '-')
		return (true);
	else
		return (false);
}

char	**parse(int ac, char **av)
{
	char	**input;

	if (ac == 2)
		input = ft_split(av[1], ' ');
	else
		input = av + 1;
	return (input);
}

int	get_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_correct_input(char **input)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (input[i])
	{
		if (!only_digit(input[i]))
			return (0);
		i++;
	}
	if (have_duplicates(input))
		error++;
	if (error > 0 || i == 1)
	{
		return (0);
	}
	return (1);
}

int	only_digit(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		while (is_sign(input[i]))
			i++;
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
