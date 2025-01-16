/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:45:23 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/16 11:27:03 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft_pimped/include/get_next_line.h"

int	do_moves(t_stack **a, t_stack **b, char *s, bool *bad_inst)
{
	if (!s)
		return (-1);
	if (!ft_strchr(s, 'b') && (!a || !*a))
		*bad_inst = true;
	if (s[0] == 's' && s[1] == 'a' && is_end_line(s[2]))
		do_sa(a, false);
	else if (s[0] == 's' && s[1] == 's' && is_end_line(s[2]))
		do_ss(a, b, false);
	else if (s[0] == 'p' && s[1] == 'a' && is_end_line(s[2]))
		do_pa(a, b, false);
	else if (s[0] == 'p' && s[1] == 'b' && is_end_line(s[2]))
		do_pb(a, b, false);
	else if (s[0] == 'r' && s[1] == 'a' && is_end_line(s[2]))
		do_ra(a, false);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && is_end_line(s[3]))
		do_rra(a, false);
	else if (ft_strchr(s, 'b') || ft_strchr(s, 'r'))
		return (do_other_moves(a, b, s, bad_inst));
	else
		return (-1);
	return (0);
}

int	do_other_moves(t_stack **a, t_stack **b, char *s, bool *bad_inst)
{
	if (!b || !*b)
		*bad_inst = true;
	if (s[0] == 's' && s[1] == 'b' && is_end_line(s[2]))
		do_sb(b, false);
	else if (s[0] == 'r' && s[1] == 'b' && is_end_line(s[2]))
		do_rb(b, false);
	else if (s[0] == 'r' && s[1] == 'r' && is_end_line(s[2]))
		do_rr(a, b, false);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && is_end_line(s[3]))
		do_rrb(b, false);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && is_end_line(s[3]))
		do_rrr(a, b, false);
	else
		return (-1);
	return (0);
}

void	checker(t_stack **stack_a, t_stack **stack_b, char **s)
{
	int		ret;
	char	*tmp;
	bool	bad_instruction;

	bad_instruction = false;
	while (*s)
	{
		ret = do_moves(stack_a, stack_b, *s, &bad_instruction);
		if (ret == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		tmp = *s;
		free(tmp);
		*s = get_next_line(0);
	}
	if (is_sorted(*stack_a) && !*stack_b && !bad_instruction)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*s;

	stack_a = init_input_and_stack(ac, av);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	s = get_next_line(0);
	checker(&stack_a, &stack_b, &s);
	free_checker(&stack_a, &stack_b, &s);
	return (0);
}



