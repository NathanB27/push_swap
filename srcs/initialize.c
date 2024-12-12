/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:28:21 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/12 16:16:59 by nboucher         ###   ########.fr       */
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


t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		//if (nb > INT_MAX || nb < INT_MIN)
		//exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

int	main(int ac,char **av)
{
	
	t_stack	*stack_a;
	int	check;
	int i;

	i = 1;
	check = check_input(av[1]);
	if (!check)
		ft_printf("correct input\n");
	ft_printf("bad input\n");
	if (ac > 2)
	{
		stack_a = fill_stack_values(ac, av);
		while (i < ac)
		{
			ft_printf("%d\n", stack_a->value);
			stack_a = stack_a->next;
			i++;
		}
	}
}
