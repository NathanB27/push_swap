/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:24:41 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/13 18:03:22 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <ft_printf.h>
#include <get_next_line.h>
#include <libft.h>
# include <stddef.h>
//# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>
# include <limits.h>
//# include <stdio.h>

typedef struct s_stack
{
	int			value;
	bool			is_cheapest;
	int			pos;
	int			cost;
	bool			is_above_med;
	struct s_stack	*next;
	struct s_stack	*target;
	struct s_stack	*previous;
}	t_stack;


char		**clean_input(char *str);
t_stack *get_last(t_stack *stack);
void	free_input(char **input, bool need_free);
t_stack		*stack_new(int value);
t_stack		*fill_stack_values(char **input);
int			get_stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
int			check_input(char *str);
int			arg_is_number(char *av);
//int			have_duplicates(char **av);
int			arg_is_zero(char *av);
int			is_correct_input(char **input);
int			is_sign(char c);
int	only_digit(char *input);
int			nbstr_cmp(const char *s1, const char *s2);
int			is_sorted(t_stack	*stack);
int			get_stack_size(t_stack *stack);
void		assign_pos(t_stack **stack);
//void		swap(t_stack *stack);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **stack);
void		do_ra(t_stack	**stack_a);
void		do_rb(t_stack	**stack_b);
void		do_rr(t_stack	**stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **src, t_stack **dest);
void		do_pa(t_stack	**stack_a, t_stack **stack_b);
void		do_pb(t_stack	**stack_b, t_stack **stack_a);
int			get_min(t_stack **stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	target_node_a(t_stack *stack_a, t_stack *stack_b);
void	target_node_b(t_stack *stack_a, t_stack *stack_b);
void	define_cheapest(t_stack *stack);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	order_a(t_stack **stack_a);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	big_algo(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack_a);

void	set_position(t_stack *stack);
void	calcul_cost(t_stack *stack_a, t_stack *stack_b);
t_stack	*get_cheapest(t_stack *stack);
t_stack	*create_stack_a(char **input);
void	reorder_stacks(t_stack **stack, t_stack *top_node, char name);
#endif
