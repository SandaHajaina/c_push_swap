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
	t_stack *a;
	t_stack	*max;

	a = stack_new(2);
	add_back(&a, 3);
	add_back(&a, 6);
	add_back(&a, 8);
	add_back(&a, 20);

	printf("%d\n", check_sorted(&a));
}

/*int main()
{
	t_stack	*a;
	t_stack	*b;
	t_stack *tmp;

	a = stack_new(5);
	b = NULL;
	tmp = a;
	add_back(&a, 4);
	add_back(&a, 10);
	add_back(&a, 13);
	add_back(&a, 14);
	add_back(&a, 15);

	sa(&a);
	ra(&a);
	rb(&a);
	ss(&a, &b);
	pb(&a, &b);
	b = stack_new(99);
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
	free_stack(&tmp);
	free_stack(&b);
	return (0);
}*/
