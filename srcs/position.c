/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:25:30 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/10 13:37:12 by nboucher         ###   ########.fr       */
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
		tmp = tmp->next;
	}
}

void is_above_med(t_stack *stack)
{
	int	len;
	int i;
	t_stack	*tmp;

	len = get_stack_size(stack);
	i = 1;
	tmp = stack;
	while (i <= ((len) / 2))
	{
		tmp->is_above_med = 1;
		tmp = tmp->next;
		i++;
	}
}

void	assign_pos(t_stack **stack)
{
	calcul_pos(*stack);
	is_above_med(*stack);
}
