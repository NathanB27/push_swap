/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:25:30 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 13:24:14 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *stack)
{
	int	i;
	int	med;

	i = 0;
	if (!stack)
		return ;
	med = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->pos = i;
		if (i <= med)
			stack->is_above_med = false;
		else
			stack->is_above_med = true;
		stack = stack->next;
		i++;
	}
}
