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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		printf("Please provide at least one number as argument.\n");
		return (1);
	}
	int n = argc - 1; // The number of arguments passed
	a = stack_new(atoi(argv[1]));
	// Add the numbers from the command line to the stack
	for (int i = 2; i < argc; i++)
	{
		add_back(&a, atoi(argv[i]));
	}
	b = NULL;
	sort_stack(&a, &b);
	free_stack(&a);
	return (0);
}
