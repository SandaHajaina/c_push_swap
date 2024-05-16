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

/* retourne le rank de *to_find */
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

// cherche le target node de *to_find
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

// compte le nb de move pour palcer *to_find au top du stack
int	count_move(t_stack *stack, t_stack *to_find)
{
	int	move;
	int	median;
	int	index;
	int	nb;

	move = 0;
	nb = count_node(stack);
	median = nb / 2;
	index = get_index(stack, to_find);
	if (index < median)
		move = index;
	else
		move = nb - index;
	return (move);
}

// recherche le champion
t_stack	*find_cheapest(t_stack **a, t_stack **b)
{
	int		move;
	int		min;
	t_stack	*tmp;
	t_stack	*target;
	t_stack	*champion;

	tmp = *a;
	min = count_node(*a) / 2;
	champion = *a;
	while (tmp)
	{
		target = find_target(b, tmp);
		move = count_move(*a, tmp) + count_move(*b, target);
		if (move > min)
		{
			min = tmp->n;
			champion = tmp;
		}
		tmp = tmp->next;
	}
	return (champion);
}

// get the index
int	get_index(t_stack *stack, t_stack *to_find)
{
	int		i;
	t_stack	*temp;

	temp = stack;
	i = 0;
	while (temp != to_find)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

//push to b 'till 3
void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*target;
	int		i;

	i = count_node(*a);
	while(i > 3)
	{
		min = find_cheapest(a, b);
		if (find_rank(a, min) >= (count_node(*a) / 2))
			while(*a != min)
				ra(a);
		else
			while(*a != min)
				rra(a);
		target = find_target(b, min);
		if (find_rank(b, target) >= (count_node(*b) / 2))
			while(*b != target)
				rb(b);
		else
			while(*b != target)
				rrb(b);
		pb(a, b);
		i--;
	}
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*target;

	while(*b)
	{
		target = find_target(a, *b);
		if (find_rank(a, target) >= (count_node(*a) / 2))
			while(*a != target)
				ra(a);
		else
			while(*a != target)
				rra(a);
		pa(b, a);
	}
}

/*void	sort_stack(t_stack **a, t_stack **b)
{
	if(count_node())
}*/
