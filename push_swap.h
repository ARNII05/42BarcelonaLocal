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
# include <stdlib.h>
# include "printf/ft_printf.h"

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}	t_stack;
t_stack	init_stack(int capacity);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	do_p(t_stack *stack_a, t_stack *stack_b, char *op_name);
void	do_rr(t_stack *stack_a, t_stack *stack_b);
void	do_s_tasks(t_stack *stack, char *op_name);
void	do_ss(t_stack *stack_a, t_stack *stack_b, char *op_name);
void	putstr(char *s, int fd);
char	*ft_itoa(int n);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(const char *s);
int		any_duplicate(int *nbr, int argc);
int		ft_is_digit(char *str);
int		ft_putchar(char c);
int		exceeding_int(long nbr);
size_t	ft_strlen(const char *c);

#endif
