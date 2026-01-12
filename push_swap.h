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

# define INT_MAX 2147483647
# define INT_MIN -2147483647

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}	t_stack;
t_stack	init_stack(int capacity);
size_t	ft_strlen(const char *c);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	do_p(t_stack *stack_a, t_stack *stack_b, char *op_name);
void	do_r(t_stack *stack, char *op_name);
void	do_rr(t_stack *stack_a, t_stack *stack_b);
void	do_rrr(t_stack *stack_a, t_stack *stack_b);
void	do_rrx(t_stack *stack, char *op_name);
void	do_s_tasks(t_stack *stack, char *op_name);
void	do_ss(t_stack *stack_a, t_stack *stack_b);
void	putstr(char *s, int fd);
void	sort_len_three(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);
long	ft_atoi(const char *str);
int		fill_stack(t_stack	*stack_a, char **argv);
int		stack_is_sorted(t_stack *stack);
char	*ft_itoa(int n);

#endif
