/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:25:30 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/06 16:07:51 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_pos(t_stack *stack)
{
	t_stack	*tmp;
	int i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->pos = i;
		i++;
	}
}

void is_above_med(t_stack *stack)
{
	int	len;
	int i;
	t_stack	*tmp;

	len = get_stack_size(t_stack *stack);
	i = 0;
	tmp = stack;
	if (len % 2 == 0)
	{
		while (i <= (len / 2))
		{
			tmp->is_above_med = 1;
			tmp = tmp->next;
			i++;
		}
	}
	else 
	{
		while (tmp)
		{
			tmp->is_above_med = 0;
			tmp = tmp->next;
		}
	}
}

void	assign_index(t_stack *stack)
{
	calcul_pos(stack);
	is_above_med(stack);
}
