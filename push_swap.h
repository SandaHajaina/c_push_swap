/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:19:13 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/01 10:20:01 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

//operations
void	swap(t_stack	**stack);

//utils
t_stack	*stack_new(int n);
t_stack	*stack_last(t_stack	*stack);
void	add_back(t_stack **stack, int n);

//free
void	free_stack(t_stack **stack);

#endif
