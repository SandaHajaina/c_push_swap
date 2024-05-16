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

int	main(void)
{
	t_stack	*a;
	t_stack	*min;
	t_stack	*b;
	t_stack	*c;

	a = stack_new(3);
	add_back(&a, 9);
	add_back(&a, 4);
	add_back(&a, 8);
	//add_back(&a, 18);

	b = stack_new(7);
	add_back(&b, 5);

	printf("%d\n", find_cheapest(&a, &b)->n);
	
	//push_to_b(&a, &b);
	//sort_three(&a);

	/*printf("====A====\n");
	while(a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
	printf("====B====\n");
	while(b)
	{
		printf("%d\n", b->n);
		b = b->next;
	}*/
}
