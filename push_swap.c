/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:18:54 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/01 10:18:57 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int main()
{
	t_stack	*a;
	t_stack *tmp;

	a = stack_new(5);
	tmp = a;
	add_back(&a, 4);
	add_back(&a, 10);
	add_back(&a, 13);


	while(1)
	{
		printf("%d\n", a->n);
		if(a->next == NULL)
			break ;
		a = a->next;
	}
	free_stack(&tmp);
	return (0);
}
