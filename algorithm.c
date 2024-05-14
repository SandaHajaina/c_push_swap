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
	while (temp)
	{
		i++;
		if (to_find == temp)
			break ;
		temp = temp->next;
	}
	return (i);
}

t_stack	*find_position(t_stack **stack, t_stack *to_find)
{
	int		n;
	t_stack	*prev;
	t_stack *temp;

	temp = *stack;
	prev = stack_min(*stack);
	n = to_find->n;
	while(temp)
	{
		if ((temp->n < n) && (temp->n > prev->n))
			prev = temp;
		temp = temp->next;
	}
	return (prev);
}

/*t_stack	*find_cheapest(t_stack **a, t_stack **b)
{
	int		step;
	t_stack	*cheapest;
	t_stack	*temp;
	t_stack	*pos;

	step = 0;
	temp = *a;
	pos = NULL;
	cheapest = temp;
	if (!(*a) || !(*b))
		return ;
	while(temp)
	{
		pos = find_position(*b, temp);
	}
}*/

int	get_index(t_stack *stack, t_stack *to_find)
{
	int		i;
	t_stack	*temp;

	temp = stack;
	i = 0;
	while(temp != to_find)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

/*void	push_to_b(t_stack **a, t_stack **b)
{
	while(count_node(*a) != 3)
	{

	}
}*/

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		median;

	if (count_node(*a) == 3)
	{
		sort_three(a);
		return ;
	}
	while (*a)
	{
		min = stack_min(*a);
		median = count_node(*a) / 2;
		if (find_rank(a, min) >= median)
		{
			while (*a != min)
				ra(a);
		}
		else
		{
			while (*a != min)
				rra(a);
		}
		pb(a, b);
	}
	while (*b)
		pa(b, a);
}
