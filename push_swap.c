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
#include <stdlib.h>
#include <time.h>

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*x;
	t_stack	*y;

	if (!a)
		return ;
	x = a;
	y = b;
	printf("====A====|====B====\n");
	while (1)
	{
		if (x)
		{
			printf("    %d     ", x->n);
			x = x->next;
		}
		else
			printf("          ");
		if (y)
		{
			printf("    %d    ", y->n);
			y = y->next;
		}
		printf("\n");
		if (x == NULL && y == NULL)
		{
			break ;
		}
	}
}

// Fonction pour échanger deux nombres
void	echanger(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Fonction pour générer une liste aléatoire de n éléments sans redondance
void	genererListeAleatoire(int *liste, int n)
{
	int	j;

	// Initialiser la liste avec des valeurs de 1 à n
	for (int i = 0; i < n; i++)
	{
		liste[i] = i + 1;
	}
	// Mélanger les éléments de la liste pour les rendre aléatoires
	for (int i = 0; i < n; i++)
	{
		j = rand() % n;
		echanger(&liste[i], &liste[j]);
	}
}

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
	return (0);
}

// int	main(void)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	int n = 499;
//     int liste[499];

//     // Initialiser le générateur de nombres aléatoires
//     srand(time(NULL));
//     genererListeAleatoire(liste, n);

// 	a = stack_new(500);

// 	// Imprimer les lignes add_back(&a, <number>);
//     for (int i = 0; i < n; i++) {
//         add_back(&a, liste[i]);
//     }

// 	b = NULL;

// 	sort_stack(&a, &b);

//     //print_stack(a, b);
// }
