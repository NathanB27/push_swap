/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:55:39 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/06 15:05:09 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

t_stack	*fill_stack_values(char **input)
{
	t_stack		*stack;
	long int	nb;
	int			i;

	stack = NULL;
	nb = 0;
	i = 0;
	while (input[i])
	{
		nb = ft_atoi(input[i]);
		//mettre des securite
		if (i == 0)
			stack = stack_new((int)nb);
		else
			stack_add_bottom(&stack, stack_new((int)nb));
		i++;
	}
	return (stack);
}

