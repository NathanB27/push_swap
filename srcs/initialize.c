/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:55:39 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/21 13:03:31 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last(t_stack *stack)
{
	while (stack)
	{
		if (!(stack->next))
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_node;

	if (stack)
	{
		if (*stack)
		{
			last_node = get_last(*stack);
			last_node->next = new;
			new->previous = last_node;
		}
		else
		{
			*stack = new;
			new->previous = NULL;
		}
	}
}

t_stack	*create_stack_a(char **input, bool tofree)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*new;

	i = 0;
	stack_a = NULL;
	while (input && input[i])
	{
		new = stack_new(ft_atoi(input[i]));
		if (!new)
		{
			free_stack(&new);
			return (NULL);
		}
		ft_stackadd_back(&stack_a, new);
		i++;
	}
	i = 0;
	while (tofree && input && input[i])
		free(input[i++]);
	if (tofree && input)
		free(input);
	return (stack_a);
}
