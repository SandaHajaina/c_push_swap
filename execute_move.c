/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:49:52 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/27 09:49:54 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_case_rrr(t_stack **a, t_stack **b, t_stack *min,
		t_stack *target)
{
	while (*a != min && *b != target)
		rrr(a, b);
	while (*a != min)
		rra(a);
	while (*b != target)
		rrb(b);
}

void	execute_case_rr(t_stack **a, t_stack **b, t_stack *min, t_stack *target)
{
	while (*a != min && *b != target)
		rr(a, b);
	while (*a != min)
		ra(a);
	while (*b != target)
		rb(b);
}

void	execute_case_ra_rb(t_stack **a, t_stack **b, t_stack *min,
		t_stack *target)
{
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
}
