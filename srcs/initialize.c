/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:55:39 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/08 10:51:12 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

