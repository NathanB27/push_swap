/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:18:53 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/16 14:19:09 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int len_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		i ++;
	}
	return (0);
}
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost = -1;
	new->next = NULL;
	return (new);
}

t_stack	*get_bottom(t_stack	*stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*get_before_bottom(t_stack *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}


void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*end;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	end = get_bottom(*stack);
	end->next = new;
}


