/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:29:01 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/13 17:55:27 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i ++;
	}
	return (s1[i] - s2[i]);
}

static bool	have_duplicates(char **input)
{
    int i;
	int j;

	i = 0;
	j = 0;
    while (input[i])
	{
        int j = i + 1;
        while (input[j])
		{
            if (ft_strcmp(input[i], input[j]) == 0)
                return true;
            j++;
    	}
        i++;
    }
    return false;
}

int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **av)
{
	int	i;
	int	nb_zeros;
	int error;

	nb_zeros = 0;
	i = 1;
	error = 0;
	while (av[i])
	{
		if (!arg_is_number(av[i]) ||  !only_digit(av[i]))
			error++;
		nb_zeros += arg_is_zero(av[i]);
		i++;
	}
	if (nb_zeros > 1)
		error++;
	if (have_duplicates(av))
		error++;
	if (error > 0 || i == 1 || nb_zeros > 1)
	{
		return (0);
	}
	return (1);
}

int	only_digit(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '-' || input[i] == '+')
			i++;
		else if (input[i] < '0' || input[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
