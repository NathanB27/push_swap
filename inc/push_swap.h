/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboucher <nboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:24:41 by nboucher          #+#    #+#             */
/*   Updated: 2025/01/21 16:55:09 by nboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ft_printf.h>
# include <get_next_line.h>
# include <libft.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	bool			is_cheapest;
	int				pos;
	int				cost;
	bool			is_above_med;
	struct s_stack	*next;
	struct s_stack	*target;
	struct s_stack	*previous;
}	t_stack;

//verif input
int		is_correct_input(char **input);
bool	have_duplicates(char **input);
bool	is_sign(char c);
int		only_digit(char *input);
int		is_sorted(t_stack	*stack);
void	free_all_alloc(char **input, t_stack **stack, bool tofree);
bool	double_zero(char **str);


// movements
void	do_sa(t_stack **stack_a, bool print);
void	do_sb(t_stack **stack_b, bool print);
void	do_ss(t_stack **stack_a, t_stack **stack_b, bool print);
void	do_ra(t_stack	**stack_a, bool print);
void	do_rb(t_stack	**stack_b, bool print);
void	do_rr(t_stack	**stack_a, t_stack **stack_b, bool print);
void	do_rra(t_stack **stack_a, bool print);
void	do_rrb(t_stack **stack_b, bool print);
void	do_rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void	do_pa(t_stack	**stack_a, t_stack **stack_b, bool print);
void	do_pb(t_stack	**stack_b, t_stack **stack_a, bool print);

//free_stack_input
void	free_stack(t_stack **stack);
void	free_input(char **input, bool need_free);

//algo
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	order_a(t_stack **stack_a);
void	algo(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack_a);
void	target_node_a(t_stack *stack_a, t_stack *stack_b);
void	target_node_b(t_stack *stack_a, t_stack *stack_b);
void	define_cheapest(t_stack *stack);
void	set_position(t_stack *stack);
void	calcul_cost(t_stack *stack_a, t_stack *stack_b);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*get_last(t_stack *stack);
t_stack	*stack_new(int value);
int		get_stack_size(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
t_stack	*create_stack_a(char **input, bool tofree);

//bonus
t_stack	*init_input_and_stack(int ac, char **av);
int		do_other_moves(t_stack **a, t_stack **b, char *s, bool bad_instruction);
bool	is_end_line(char c);
void	free_checker(t_stack **stack_a, t_stack **b, char **str);

#endif
