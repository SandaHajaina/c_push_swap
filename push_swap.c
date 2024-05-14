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

	a = stack_new(200);
	add_back(&a, -10);
	add_back(&a, 6);
	add_back(&a, 9);
	add_back(&a, 20);
	add_back(&a, 12);
	add_back(&a, -1);
	add_back(&a, 0);
	add_back(&a, 26);
	b = stack_min(a);

	printf("%d\n", get_index(a, b));
	printf("%d\n", a->n);
	/*while(a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}*/
}
