/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:51:28 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/13 11:51:48 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push to b 'till 3
void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*target;
	int		i;

	i = count_node(*a);
	while (i > 3)
	{
		min = find_cheapest(a, b);
		target = find_target(b, min);
		if (find_rank(a, min) > get_median(*a) && find_rank(b,
				target) > get_median(*b))
		{
			while (*a != min && *b != target)
				rrr(a, b);
			while (*a != min)
				rra(a);
			while (*b != target)
				rrb(b);
			pb(a, b);
			i--;
			continue ;
		}
		if (find_rank(a, min) < get_median(*a) && find_rank(b,
				target) < get_median(*b))
		{
			while (*a != min && *b != target)
				rr(a, b);
			while (*a != min)
				ra(a);
			while (*b != target)
				rb(b);
			pb(a, b);
			i--;
			continue ;
		}
		if (find_rank(a, min) <= get_median(*a))
			while (*a != min)
				ra(a);
		else
			while (*a != min)
				rra(a);
		if (find_rank(b, target) <= get_median(*b))
			while (*b != target)
				rb(b);
		else
			while (*b != target)
				rrb(b);
		pb(a, b);
		i--;
	}
}

// push back all numbers from b to a (b -> a)
void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*min;

	while (*b)
	{
		target = find_position(a, *b);
		if (find_rank(a, target) <= (get_median(*a)))
			while (*a != target)
				ra(a);
		else
			while (*a != target)
				rra(a);
		pa(b, a);
	}
	min = stack_min(*a);
	if ((find_rank(a, min)) <= (get_median(*a)))
		while (*a != min)
			ra(a);
	else
		while (*a != min)
			rra(a);
}

// sorting the stack
void	sort_stack(t_stack **a, t_stack **b)
{
	if (check_sorted(a))
		return ;
	if (count_node(*a) == 2)
	{
		if (!check_sorted(a))
			sa(a);
		return ;
	}
	else if (count_node(*a) == 3)
	{
		sort_three(a);
		return ;
	}
	else if (count_node(*a) == 4)
		pb(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
	}
	push_to_b(a, b);
	sort_three(a);
	push_to_a(a, b);
}
