/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:18:53 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/15 13:33:27 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->pos = 0;
	new->cost = 0;
	new->is_cheapest = false;
	new->is_above_med = false;
	new->target = NULL;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}
