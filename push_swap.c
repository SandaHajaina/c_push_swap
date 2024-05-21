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

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	int n = 99;
    int liste[100];

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));
    genererListeAleatoire(liste, n);

	a = stack_new(201);
	// Imprimer les lignes add_back(&a, <number>);
    for (int i = 0; i < n; i++) {
        add_back(&a, liste[i]);
    }

	b = NULL;

	sort_stack(&a, &b);

	printf("====A====\n");
	while(a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}
