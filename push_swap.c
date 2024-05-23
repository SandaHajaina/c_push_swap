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

// Fonction pour échanger deux nombres
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour générer une liste aléatoire de n éléments sans redondance
void genererListeAleatoire(int *liste, int n) {
    // Initialiser la liste avec des valeurs de 1 à n
    for (int i = 0; i < n; i++) {
        liste[i] = i + 1;
    }

    // Mélanger les éléments de la liste pour les rendre aléatoires
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        echanger(&liste[i], &liste[j]);
    }
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	if (argc < 2) {
// 		printf("Please provide at least one number as argument.\n");
// 		return 1;
// 	}

// 	int n = argc - 1; // The number of arguments passed

// 	a = stack_new(atoi(argv[1]));
// 	// Add the numbers from the command line to the stack
//     for (int i = 2; i < argc; i++) {
//         add_back(&a, atoi(argv[i]));
//     }

// 	b = NULL;

// 	sort_stack(&a, &b);

// 	return 0;
// }

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	int n = 99;
    int liste[99];

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));
    genererListeAleatoire(liste, n);

	a = stack_new(6);
    add_back(&a, 9);
    add_back(&a, 1);
    add_back(&a, 4);
    add_back(&a, 3);
    add_back(&a, 2);
	// Imprimer les lignes add_back(&a, <number>);
    // for (int i = 0; i < n; i++) {
    //     add_back(&a, liste[i]);
    // }

	b = stack_new(8);
    add_back(&b, 7);
    add_back(&b, 5);
    add_back(&b, 10);

    t_stack *min = find_cheapest(&a, &b);
    printf("cheapest: %d | target: %d\n", min->n, find_target(&b, min)->n);
	//sort_stack(&a, &b);
}
