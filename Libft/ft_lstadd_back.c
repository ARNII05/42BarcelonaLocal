/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                  	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 11:18:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/15 11:18:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *actual_node;

	actual_node = *alst;
	if (*alst)
	{
		while (actual_node->next != NULL)
			actual_node = actual_node->next;
		actual_node->next = new;
	}
	if (!*alst)
		*alst = new;
}