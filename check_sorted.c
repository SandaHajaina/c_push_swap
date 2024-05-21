/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:13:16 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/11 14:13:18 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (!(*stack))
		return (0);
	temp = *stack;
	next = NULL;
	while (temp->next)
	{
		next = temp->next;
		if (temp->n >= next->n)
			return (0);
		temp = next;
	}
	return (1);
}

int	check_duplicate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*left;
	int		n;

	temp = *stack;
	while (temp)
	{
		left = (temp)->next;
		n = temp->n;
		while (left)
		{
			if (n == left->n)
				return (0);
			left = left->next;
		}
		temp = temp->next;
	}
	return (1);
}
