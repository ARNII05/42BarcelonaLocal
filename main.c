/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
//ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

/*
static void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int total_operations;

	total_operations = stack_a->n_operations + stack_b->n_operations;
	if (total_operations == 0)
	{
		printf("Numbers are alredy sorted");
		return ;
	}
	if (stack_is_sorted(stack_a))
		printf("Is sorted");
	else
		printf("Is not sorted");
	printf("\nList: ");
	for (int i = 0; i < stack_a->size; i++)
		printf("%d ", stack_a->data[i]);
	printf("\nTotal operations: %d\n", total_operations);
}
*/

static void	free_split(char **s, int did_split)
{
	int	i;

	if (did_split != 1)
		return ;
	i = 0;
	if (!s)
		return ;
	while (s[i])
		free(s[i++]);
	free(s);
}

static int	has_one_arg(int argc, char ***argv)
{
	char	**tmp;

	if (argc != 2)
		return (0);
	tmp = ft_split((*argv)[1], ' ');
	if (!tmp)
	{
		free_split(tmp, 1);
		return (-1);
	}
	*argv = tmp;
	return (1);
}

static int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		did_split;

	did_split = has_one_arg(argc, &argv);
	if (!did_split)
		argv = argv + 1;
	stack_a = init_stack(argv_len(argv));
	stack_b = init_stack(argv_len(argv));
	if (!stack_a.data || !stack_b.data)
		return (0);
	if (fill_stack(&stack_a, argv))
	{
		free(stack_a.data);
		free_split(argv, did_split);
		return (free(stack_b.data), putstr("Error\n", 2), 0);
	}
	if (stack_a.size >= 2 && !stack_is_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	free_split(argv, did_split);
	return (free(stack_a.data), free(stack_b.data), 1);
}
