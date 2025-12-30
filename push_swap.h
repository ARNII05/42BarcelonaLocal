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

char	*push_swap(int *nbrs);
size_t	ft_strlen(const char *c);
char	*ft_itoa(int n);
int		any_errors(int *nbrs, int argc);
int		any_duplicate(int *nbr, int argc);
char	*ft_strchr(const char *string, int c);
int		ft_is_digit(char *str);

#endif
