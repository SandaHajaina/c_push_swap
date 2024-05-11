/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:27:52 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 16:27:56 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*temp;
	int		n;

	max = stack;
	temp = stack;
	n = stack->n;
	while(temp)
	{
		if(n < temp->n)
		{
			max = temp;
			n = temp->n;
		}
		temp = temp->next;
	}
	return (max);
}

t_stack	*stack_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*temp;
	int		n;

	min = stack;
	temp = stack;
	n = stack->n;
	while(temp)
	{
		if(n > temp->n)
		{
			min = temp;
			n = temp->n;
		}
		temp = temp->next;
	}
	return (min);
}
