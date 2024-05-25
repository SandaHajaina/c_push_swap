/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:29:12 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/25 16:29:14 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count the move nb to put the given node to the top of the stack
int	count_move(t_stack *stack, t_stack *to_find)
{
	int	move;
	int	median;
	int	index;
	int	nb;

	move = 0;
	nb = count_node(stack);
	median = get_median(stack);
	index = get_index(stack, to_find);
	if (index <= median)
		move = index;
	else
		move = nb - index;
	return (move);
}

// count the total move to put the node and its target to the top (a | b)
int	total_move(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	int	index_a;
	int	index_b;
	int	median_a;
	int	median_b;
	int	move;

	index_a = find_rank(a, node);
	index_b = find_rank(b, target);
	median_a = get_median(*a);
	median_b = get_median(*b);
	if (index_a <= median_a && index_b <= median_b)
		move = max(count_move(*a, node), count_move(*b, target));
	else if (index_a > median_a && index_b > median_b)
		move = max(count_move(*a, node), count_move(*b, target));
	else
		move = count_move(*a, node) + count_move(*b, target);
	return (move);
}

// find the target node to a given node (from a to b)
t_stack	*find_target(t_stack **stack, t_stack *to_find)
{
	int		n;
	t_stack	*prev;
	t_stack	*temp;

	temp = *stack;
	prev = stack_min(*stack);
	n = to_find->n;
	if (n < prev->n)
		return (stack_max(*stack));
	while (temp)
	{
		if ((temp->n < n) && (temp->n > prev->n))
			prev = temp;
		temp = temp->next;
	}
	return (prev);
}

// find the right position of a node from b to a (b -> a)
t_stack	*find_position(t_stack **stack, t_stack *to_find)
{
	int		n;
	t_stack	*next;
	t_stack	*temp;

	temp = *stack;
	next = stack_max(*stack);
	n = to_find->n;
	if (n > next->n)
		return (stack_min(*stack));
	while (temp)
	{
		if ((temp->n > n) && (temp->n < next->n))
			next = temp;
		temp = temp->next;
	}
	return (next);
}

// find the node with the lowest operating cost
t_stack	*find_cheapest(t_stack **a, t_stack **b)
{
	int		move;
	int		min;
	t_stack	*tmp;
	t_stack	*target;
	t_stack	*lowest;

	tmp = *a;
	if (count_node(*a) < count_node(*b))
		min = get_median(*b);
	else
		min = get_median(*a);
	lowest = *a;
	while (tmp)
	{
		target = find_target(b, tmp);
		move = total_move(a, b, tmp, target);
		if (move < min)
		{
			min = move;
			lowest = tmp;
		}
		tmp = tmp->next;
	}
	return (lowest);
}
