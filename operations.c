/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:21:43 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/04 11:22:05 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;
	int		n;

	if (!(*stack))
		return ;
	if ((*stack)->next == NULL || !(*stack))
		return ;
	temp = (*stack)->next;
	n = (temp)->n;
	(temp)->n = (*stack)->n;
	(*stack)->n = n;
}

void	push(t_stack **src, t_stack **target)
{
	t_stack	*temp;
	int		n;

	if (!(*src))
		return ;
	if (!(*target))
	{
		n = (*src)->n;
		temp = (*src)->next;
		free(*src);
		*src = temp;
		*target = stack_new(n);
	}
	else
	{
		temp = (*src)->next;
		(*src)->next = *target;
		*target = *src;
		*src = temp;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;
	t_stack	*last;

	if (!(*stack))
		return ;
	next = (*stack)->next;
	temp = (*stack);
	last = stack_last(*stack);
	(*stack)->next = NULL;
	last->next = temp;
	(*stack) = next;
}

void	reverse(t_stack **stack)
{
	t_stack	*current;
	t_stack	*prev;

	if(!(*stack) || (*stack)->next == NULL)
		return ;
	current = *stack;
	prev = NULL;
	while(current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}
