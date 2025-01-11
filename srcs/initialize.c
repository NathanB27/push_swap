/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:55:39 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/11 16:22:59 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

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

static t_stack *get_last(t_stack *stack)
{
	while(stack)
	{
		stack = stack->next;
	}
	return (stack);
}

static void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_node;

	if (stack)
	{
		if (*stack)
		{
			last_node = get_last(*stack);
			ft_printf("ya pas de stack \n");
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


t_stack	*create_stack_a(char **input)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*new;

	i = 0;
	stack_a = NULL;
	while (input && input[i])
	{
		new = stack_new(ft_atoi(input[i]));
		ft_printf("stack_new work \n");
		if (!new)
		{
			return (NULL);
		}
		ft_stackadd_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

