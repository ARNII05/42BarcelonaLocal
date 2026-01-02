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

void	push_swap(int **stack_a, int argc);
void do_pa(int **stack_a, int **stack_b);
void do_pb(int **stack_a, int **stack_b);
void do_ra(int **stack_a);
void do_rb(int **stack_a);
void do_rr(int **stack_a, int **stack_b);
void do_sa(int **stack_a, int argc);
void do_sb(int **stack_a, int argc);
void do_ss(int **stack_a, int **stack_b, int argc);
void	putstr(char *s);
size_t	ft_strlen(const char *c);
char	*ft_itoa(int n);
int		any_errors(int *nbrs, int argc);
int		any_duplicate(int *nbr, int argc);
int	ft_putchar(char c);
char	*ft_strchr(const char *string, int c);
char	*ft_strdup(const char *s);
int		ft_is_digit(char *str);

#endif
