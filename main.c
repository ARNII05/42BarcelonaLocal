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

//Check norminette, checker_OS and memory leaks
//Output must be only either Error or any operation
//Update Makefile

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
	printf("\nTotal operations: %d", total_operations);
}
*/

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack(argc - 1);
	stack_b = init_stack(argc - 1);
	if (!stack_a.data || !stack_b.data)
		return (0);
	if (fill_stack(&stack_a, argv))
	{
		free(stack_a.data);
		return (free(stack_b.data), putstr("Error\n", 2), 0);
	}
	if (stack_a.size >= 2 && !stack_is_sorted(&stack_a))
		push_swap(&stack_a, &stack_b);
	return (free(stack_a.data), free(stack_b.data), 1);
}
