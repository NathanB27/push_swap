/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:22:19 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/21 16:37:23 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(char **input, bool need_free)
{
	int	i;

	i = 0;
	if (need_free && input)
	{
		while (input[i])
		{
			free(input[i]);
			i++;
		}
		free(input);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_all_alloc(char **input, t_stack **stack, bool tofree)
{
	free_input(input, tofree);
	free_stack(stack);
}
