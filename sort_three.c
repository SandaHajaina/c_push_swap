/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:49:50 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/10 14:49:52 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = stack_max(*stack);
	if ((*stack)->n == max->n)
		ra(stack);
	else if ((*stack)->next->n == max->n)
		rra(stack);
	if ((*stack)->n > (*stack)->next->n)
		sa(stack);
}
