/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:44:53 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/13 17:56:46 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

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
	char **input;
	if (ac == 2)
	{
		input = ft_split(av[1], ' ');
	}
	else
	{
		input = av + 1;	
	}
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

/*
bool	arg_is_number(char *av)
{
	int	i;

	i = 0;
	while (is_sign(av[i]) && av[i + 1] != '\0')
		i++
	return (true);
}
*/
