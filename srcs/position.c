/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:25:30 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/11 14:30:25 by nboucher         ###   ########.fr       */
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
			stack->is_above_med = 0;
		else
			stack->is_above_med = 1;
		stack = stack->next;
		i++;
	}
}

