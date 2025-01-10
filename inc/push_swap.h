/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:24:41 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/10 14:58:45 by nboucher         ###   ########.fr       */
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
# include <limits.h>
//# include <stdio.h>

typedef struct s_stack
{
	int			value;
	int			is_cheapest;
	int			pos;
	int			cost;
	int			is_above_med;
	struct s_stack	*next;
	struct s_stack	*target;
	struct s_stack	*previous;
}	t_stack;


char		**clean_input(char *str);
int 		len_ptr(char **ptr);
t_stack		*stack_new(int value);
t_stack		*fill_stack_values(char **input);
int			get_stack_size(t_stack *stack);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*get_bottom(t_stack *stack);
t_stack 	*get_before_bottom(t_stack	*stack);
int			check_input(char *str);
int			arg_is_number(char *av);
int			have_duplicates(char **av);
int			arg_is_zero(char *av);
int			is_correct_input(char **av);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
char		**parse(int ac, char **av);
int			is_sorted(t_stack	*stack);
int			get_stack_size(t_stack *stack);
void		assign_pos(t_stack **stack);
//void		assign_index(t_stack *stack_a, int stack_size);
void		tiny_sort(t_stack **stack_a);
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
void		first_mov(t_stack **stack_a, t_stack **stack_b);
void		cost_tobe_summit(t_stack *stack_a);
void		assign_cost(t_stack *stack_a, t_stack *stack_b);
int			get_value_nearest(int value, t_stack **stack_b);
int			get_min(t_stack **stack);
void		is_above_med(t_stack *stack);
void		fonction_test(t_stack **stack_a, t_stack **stack_b);
void	reorder_stacks(t_stack **stack, t_stack *top_node, char name);
t_stack	*get_ptr(int value, t_stack *stack_b);
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

#endif
