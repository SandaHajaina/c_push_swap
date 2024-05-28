/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:19:13 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/01 10:20:01 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

//algorithm
void	sort_stack(t_stack **a, t_stack **b);
int		find_rank(t_stack **stack, t_stack *to_find);
t_stack	*find_target(t_stack **stack, t_stack *to_find);
t_stack	*find_position(t_stack **stack, t_stack *to_find);
int		get_index(t_stack *stack, t_stack *to_find);
int		count_move(t_stack *stack, t_stack *to_find);
int		total_move(t_stack **a, t_stack **b, t_stack *node, t_stack *target);
t_stack	*find_cheapest(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);

//execute move
void	execute_case_rrr(t_stack **a, t_stack **b,
			t_stack *min, t_stack *target);
void	execute_case_rr(t_stack **a, t_stack **b,
			t_stack *min, t_stack *target);
void	execute_case_ra_rb(t_stack **a, t_stack **b,
			t_stack *min, t_stack *target);

//operations
void	swap(t_stack	**stack);
void	push(t_stack **src, t_stack **target);
void	rotate(t_stack **stack);
void	reverse(t_stack **reverse);

void	sa(t_stack	**a);
void	sb(t_stack	**b);
void	ss(t_stack	**a, t_stack **b);

void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//utils
t_stack	*stack_new(int n);
t_stack	*stack_last(t_stack	*stack);
void	add_back(t_stack **stack, int n);
void	add_front(t_stack **stack, int n);
int		count_node(t_stack *stack);
int		max(int a, int b);
int		check_sorted(t_stack **stack);
int		get_median(t_stack *stack);

// input utils
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);

//check error
int		check_error(char **n);

//free
void	free_stack(t_stack **stack);

//find min | max
t_stack	*stack_max(t_stack *stack);
t_stack	*stack_min(t_stack *stack);

//sort_three
void	sort_three(t_stack **stack);

#endif
