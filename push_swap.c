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

char	*join_all(int argc, char *argv[])
{
	char	*numbers;
	char	*tmp;
	char	*with_space;
	int		i;

	numbers = ft_strdup("");
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			tmp = ft_strjoin(numbers, argv[i]);
			free(numbers);
			with_space = ft_strjoin(tmp, " ");
			free(tmp);
			numbers = with_space;
			i++;
		}
	}
	return (numbers);
}

char	**parse_input(int argc, char *argv[])
{
	char	*params;
	char	**n;

	params = join_all(argc, argv);
	n = ft_split(params, ' ');
	free(params);
	return (n);
}

static void	fill_stack(t_stack **a, char **n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		add_back(a, ft_atoi(n[i]));
		free(n[i++]);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**n;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		n = parse_input(argc, argv);
		if (check_error(n))
		{
			write(0, "Error\n", 6);
			return (free(n), 0);
		}
		fill_stack(&a, n);
		free(n);
		sort_stack(&a, &b);
		free_stack(&a);
	}
	return (0);
}
