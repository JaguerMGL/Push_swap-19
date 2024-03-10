/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:44 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:21:16 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_node **lst)
{
	t_node	*tmp;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	(*lst)->next->prev = *lst;
	prependnode(lst, tmp);
	(*lst)->prev = NULL;
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
