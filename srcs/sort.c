/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:31 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/08 16:19:31 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	first_mov(t_stack **stack_a, t_stack **stack_b)
{
	do_pb(stack_a, stack_b);
	do_pb(stack_a, stack_b);
}


void	go_to_summit_a(t_stack *stack_a)
{
	while (stack_a->pos != 0)
	{
		if (stack_a->pos == 1)
		{
			do_sa(&stack_a);
		}
		else if (stack_a->is_above_med == 1)
		{
			do_ra(&stack_a);
		}
		else
		{
			do_rra(&stack_a);
		}
		assign_pos(stack_a);
	}
}

void	go_to_summit_b(t_stack *stack_b)
{
	while (stack_b->pos != 0)
	{
		if (stack_b->pos == 1)
		{
			do_sa(&stack_b);
		}
		else if (stack_b->is_above_med == 1)
		{
			do_ra(&stack_b);
		}
		else
		{
			do_rra(&stack_b);
		}
		assign_pos(stack_b);
	}
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	do_pb(stack_b, stack_a);

	if ((*stack_b)->value < (*stack_b)->next->value)
	{
		do_sb(stack_b);
		ft_printf("test de do_sb\n");

	}
}

/*
t_stack	*get_cheapest(t_stack *stack_a)
{
	t_stack	*tmp;
	int		lowest;
	t_stack	*ptr_cheap;
	
	tmp = stack_a;
	lowest = (stack_a)->cost;

	while (tmp)
	{
		if ((tmp)->cost < lowest)
		{
			lowest = tmp->cost;
			ptr_cheap = tmp;
		}
		tmp = tmp->next;
	}
	return (tmp);
}
*/
static t_stack	*get_cheapest(t_stack *stack_a)
{
	t_stack	*tmp;
	int		lowest;
	t_stack	*ptr_cheap;

	if (!stack_a) // Vérifie si la liste est vide
		return (NULL);

	tmp = stack_a;
	lowest = tmp->cost;
	ptr_cheap = tmp; // Initialise ptr_cheap avec le premier nœud

	while (tmp)
	{
		if (tmp->cost < lowest)
		{
			lowest = tmp->cost;
			ptr_cheap = tmp;
		}
		tmp = tmp->next;
	}
	return (ptr_cheap); // Retourne ptr_cheap, pas tmp
}


void	pleure_sur_le_poulet(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*target_a;

	assign_cost(*stack_a, *stack_b);
	
	tmp_a = get_cheapest(*stack_a);
	
	target_a = tmp_a->target;
	ft_printf("test\n");
	go_to_summit_a(tmp_a);
	go_to_summit_b(target_a);
	push_a_to_b(&tmp_a, stack_b);
	ft_printf("test2222\n");
	
	//assign_cost(*stack_a, *stack_b);
}
