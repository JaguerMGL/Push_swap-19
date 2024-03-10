/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:25 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:21:40 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_smallest(t_node *lst)
{
	t_node	*smallest;

	smallest = lst;
	while (lst)
	{
		if ((lst)->value < smallest->value)
			smallest = lst;
		lst = (lst)->next;
	}
	return (smallest);
}

void	prependnode(t_node **lst, t_node *new)
{
	if (new == NULL)
		return ;
	if (*lst != NULL)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	*lst = new;
	(*lst)->prev = NULL;
}

void	set_top(t_node **a, t_node **b, t_node *cheapest)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(*a);
	len_b = ft_lstlen(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rrr_amedian(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rr_bmedian(a, b, cheapest);
	else if (!cheapest->above_median && cheapest->target->above_median)
	{
		full_rb(b, cheapest->index);
		full_rra(a, len_a - cheapest->target->index);
	}
	else if (cheapest->above_median && !cheapest->target->above_median)
	{
		full_rrb(b, len_b - cheapest->index);
		full_ra(a, cheapest->target->index);
	}
}
