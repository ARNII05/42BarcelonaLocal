/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647L
# define INT_MIN -2147483647L

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
	int	n_operations;
}	t_stack;
long long	ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *c);
t_stack		init_stack(int capacity);
void		push_swap(t_stack *stack_a, t_stack *stack_b);
void		do_p(t_stack *stack_a, t_stack *stack_b, char *op_name);
void		do_r(t_stack *stack, char *op_name);
void		do_rrx(t_stack *stack, char *op_name);
void		do_s_tasks(t_stack *stack, char *op_name);
void		putstr(char *s, int fd);
void		sort_len_three(t_stack *stack);
void		set_index(t_stack *stack);
void		sort_index(t_stack *stack_a, t_stack *stack_b);
void		sort_int(int *n, int size);
int			fill_stack(t_stack	*stack_a, char **argv);
int			stack_is_sorted(t_stack *stack);
int			stack_max_bits(t_stack *stack_a);
int			*copy_int(int cap, int *n);

#endif
