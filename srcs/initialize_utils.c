/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:18:53 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/22 13:49:48 by nboucher         ###   ########.fr       */
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

static int	nbstr_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

bool	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (double_zero(av))
		return (true);
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
