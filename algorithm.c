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

int	find_rank(t_stack **stack, t_stack *to_find)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while(temp)
	{
		i++;
		if(to_find == temp)
			break;
		temp = temp->next;
	}
	return (i);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		median;

	median = count_node(*a) / 2;
	if (count_node(*a) == 3)
	{
		sort_three(a);
		return;
	}
	while(*a)
	{
		min = stack_min(*a);
		while(*a != min)
		{
			//if()
			ra(a);
		}
		pb(a, b);
	}
	while(*b)
		pa(b, a);
}
