/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:51:01 by sranaivo          #+#    #+#             */
/*   Updated: 2024/05/27 14:51:03 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (*(str + i))
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_number(char **n)
{
	int	i;

	i = -1;
	while (n[++i])
		if (!is_number(n[i]))
			return (0);
	return (1);
}

static int	check_duplicate(char **n)
{
	int	i;
	int	j;
	int	a;
	int	b;

	i = -1;
	while (n[++i])
	{
		j = i;
		while (n[++j])
		{
			a = ft_atoi(n[i]);
			b = ft_atoi(n[j]);
			if ((int)a == (int)b)
				return (0);
		}
	}
	return (1);
}

int	check_error(char **n)
{
	if (!(check_number(n)))
		return (1);
	if (!(check_duplicate(n)))
		return (1);
	return (0);
}
