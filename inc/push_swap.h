/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:24:41 by nboucher          #+#    #+#             */
/*   Updated: 2024/12/12 13:59:27 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <ft_printf.h>
#include <get_next_line.h>
#include <libft.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost;
	struct s_stack	*next;
}	t_stack;

char	**clean_input(char *str);
int len_ptr(char **ptr);
t_stack	*stack_new(int value);
t_stack	*fill_stack_values(int ac, char **av);
int	get_stack_size(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack *new);
t_stack	*get_bottom(t_stack *stack);
int	check_input(char *str);



#endif
