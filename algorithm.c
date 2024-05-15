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

t_stack	*find_target(t_stack **stack, t_stack *to_find)
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

int	count_move(t_stack **stack, t_stack *to_find)
{
	int	move;
	int	median;
	int	index;
	int	nb;

	move = 0;
	nb = count_node(*stack);
	median = nb / 2;
	index = get_index(*stack, to_find);
	if (index < median)
		move = index;
	else
		move = nb - index;
	return (move);
}

t_stack	*find_cheapest(t_stack **a, t_stack **b)
{
	int		move;
	t_stack *tmp;
	t_stack	*target;
	t_stack	*cheapest;

	tmp = *a;
	while(tmp)
	{
		target = find_target(*b, tmp);
		if (!move || )
		move = count_move(*a, tmp) + count_move(*b, target);
		tmp = tmp->next;
	}
}

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
