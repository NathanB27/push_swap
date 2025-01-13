/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:29:01 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/13 08:47:24 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

int	have_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nbstr_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

int	is_correct_input(char **input)
{
	int	i;
	int	nb_zeros;
	int error;

	nb_zeros = 0;
	i = 1;
	error = 0;
	while (input[i])
	{
		if (!arg_is_number(input[i]))
			error++;
		nb_zeros += arg_is_zero(input[i]);
		i++;
	}
	if (nb_zeros > 1)
		error++;
	if (have_duplicates(input))
		error++;
	if (error > 0 || i == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

