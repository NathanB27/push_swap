/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:22:19 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/13 10:22:19 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

void	free_stack(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		free(*stack_a);
		(*stack_a) = (*stack_a)->next;
	}
	free(stack_a);
	if (*stack_b)
	{
		while (*stack_b)
		{
			free(*stack_b);
			(*stack_b) = (*stack_b)->next;
		}
		free(stack_b);
	}
}

//void	free_all(char **input)

