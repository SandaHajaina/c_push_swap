/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:24:40 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/04 15:24:55 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_back(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*temp;

	if (!stack)
		return ;
	new = stack_new(n);
	temp = stack_last(*stack);
	temp->next = new;
}

void	add_front(t_stack **stack, int n)
{
	t_stack	*new;

	if (!(*stack))
		return ;
	new = stack_new(n);
	new->next = (*stack);
	*stack = new;
}

int	count_node(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	if (!stack)
		return (0);
	i = 1;
	temp = stack;
	while (temp->next)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
