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

/*int main()
{
	t_stack	*a;

	a = stack_new(5);
	add_back(&a, 10);
	add_back(&a, 7);
	add_back(&a, -4);
	add_back(&a, 0);
	add_back(&a, 11);

	reverse(&a);
	t_stack *last = stack_last(a);
	while(1)
	{
		printf("%d\n",a->n);
		if (a->next == NULL)
			break;
		a = a->next;
	}

	return (0);
}*/

int main()
{
	t_stack	*a;
	t_stack	*b;
	t_stack *tmp;

	a = stack_new(5);
	tmp = a;
	add_back(&a, 4);
	add_back(&a, 10);
	add_back(&a, 13);
	add_back(&a, 14);
	add_back(&a, 15);

	b = stack_new(99);
	rotate(&a);
	push(&b, &a);
	rotate(&a);
	push(&a, &b);
	reverse(&a);
	while(1)
	{
		printf("%d\n", a->n);
		if(a->next == NULL)
			break ;
		a = a->next;
	}
	printf("-------\n");
	while(1)
	{
		printf("%d\n", b->n);
		if(b->next == NULL)
			break ;
		b = b->next;
	}
	//free_stack(&tmp);
	return (0);
}
