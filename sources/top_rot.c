/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:30:50 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:20:56 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	top_rr(t_node **a, t_node **b, int pos)
{
	while (pos > 0)
	{
		rr(a, b);
		pos--;
	}
}

void	top_rrr(t_node **a, t_node **b, int pos)
{
	while (pos > 0)
	{
		rrr(a, b);
		pos--;
	}
}

void	rr_bmedian(t_node **a, t_node **b, t_node *cheapest)
{
	if (cheapest->index > cheapest->target->index)
	{
		top_rr(a, b, cheapest->target->index);
		full_rb(b, cheapest->index - cheapest->target->index);
	}
	else if (cheapest->index <= cheapest->target->index)
	{
		top_rr(a, b, cheapest->index);
		full_ra(a, cheapest->target->index - cheapest->index);
	}
}

void	rrr_amedian(t_node **a, t_node **b, t_node *cheapest)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(*a);
	len_b = ft_lstlen(*b);
	if (len_b - cheapest->index > len_a - cheapest->target->index)
	{
		top_rrr(a, b, len_a - cheapest->target->index);
		full_rrb(b, (len_b - cheapest->index) - 
			(len_a - cheapest->target->index));
	}
	else if (len_b - cheapest->index <= len_a - cheapest->target->index)
	{
		top_rrr(a, b, len_b - cheapest->index);
		full_rra(a, (len_a - cheapest->target->index) - 
			(len_b - cheapest->index));
	}
}
