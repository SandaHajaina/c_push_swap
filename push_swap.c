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
#include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	if (argc < 2)
// 	{
// 		printf("Please provide at least one number as argument.\n");
// 		return (1);
// 	}
// 	int n = argc - 1; // The number of arguments passed
// 	a = stack_new(atoi(argv[1]));
// 	// Add the numbers from the command line to the stack
// 	for (int i = 2; i < argc; i++)
// 	{
// 		add_back(&a, atoi(argv[i]));
// 	}
// 	b = NULL;
// 	sort_stack(&a, &b);
// 	// print_stack(a, b);
// 	free_stack(&a);
// 	return (0);
// }

char	*ft_strdup(const char *s)
{
	char	*str;
	int	i;

	str = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int	i;
	int	j;
	int	len_s1;
	int	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (j < len_s1)
		str[i++] = s1[j++];
	j = 0;
	while (j < len_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*join_all(int argc, char *argv[])
{
	char    *numbers;
	char	*tmp;
	char	*with_space;
    int     i;

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

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
    char    *params;
	char	**n;
	int		i;

	params = join_all(argc, argv);
	n = ft_split(params, ' ');
	i = 0;
	
	a = stack_new(ft_atoi(n[i]));
	b = NULL;
	free(n[i++]);
	while (n[i])
	{
		if (!is_number(n[i]))
		{
			//free_all();
			write(0, "Error\n", 6);
			return (0);
		}
		add_back(&a, ft_atoi(n[i]));
		//free(n[i++]);
		i++;
	}
    free(params);
    free(n);
	sort_stack(&a, &b);
	free_stack(&a);
    return (0);
}
