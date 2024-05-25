/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:33:46 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/25 16:33:49 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return the rank of a given node */
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

int	get_median(t_stack *stack)
{
	int	n;

	n = count_node(stack);
	if (n % 2 == 0)
		return (n / 2);
	return ((n / 2) + 1);
}

// get the index of a given node from its stack
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

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
