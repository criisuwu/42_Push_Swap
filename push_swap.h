/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:34:12 by chomobon          #+#    #+#             */
/*   Updated: 2025/04/11 18:21:09 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void	sa(t_stack **stack);
void	push(t_stack **src, t_stack **dest, char stackdest);
void	rotate(t_stack **stack, char option);
void	rr(t_stack **a, t_stack **b);
void	r_rotate(t_stack **stack, char option);
void	rrr(t_stack **a, t_stack **b);
int		check_dup(t_stack *stack);
int		check_sorted(t_stack *stack);
t_stack	*lstlast(t_stack *lst);
t_stack	*ft_process(int argc, char **argv, int *size);
void	freestr(char **lst);
void	add_back(t_stack **lst, t_stack *new);
t_stack	*new_stack(int content);
void	ft_print_err(void);
void	sort_stack(t_stack **a, t_stack **b, int size);
void	freestack(t_stack **s);
void	free_both_stacks(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	sort_mt_three(t_stack **a, t_stack **b, int sz);
void	asg_tg_pos_lower_ind(t_stack **a, t_stack **b);
void	calculate_pos(t_stack *s);
void	assign_target_pos(t_stack **a, t_stack **b);
void	asg_cost(t_stack **b, int sz_a, int sz_b);
void	ex_opt_mvs(t_stack **a, t_stack **b, int *sz_a, int *sz_b);
void	rotate_until_sorted(t_stack **a, int sz_a);
int		abs_val(int num);
void	assign_index(t_stack *a, int size);
int		is_sorted(t_stack *a);
int		ft_n_atoi(const char *str);

#endif
