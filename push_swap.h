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
 int *data;   
 int size;    
 int cap;     
} t_stack;
void	push_swap(t_stack *stack_a, t_stack *stack_b);
void do_pa(int **stack_a, int **stack_b);
void do_pb(int **stack_a, int **stack_b);
void do_ra(int **stack_a);
void do_rb(int **stack_a);
void do_rr(int **stack_a, int **stack_b);
void do_s_tasks(int **stack, int len, char *op_name);
void do_ss(int **stack_a, int **stack_b, int *len, char *op_name);
void	putstr(char *s);
char	*ft_itoa(int n);
int		any_duplicate(int *nbr, int argc);
int		ft_is_digit(char *str);
int		ft_putchar(char c);
int	exceeding_int(long nbr);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *c);

#endif
