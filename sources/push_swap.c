/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:28 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:21:43 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	finish(t_node **a)
{
	t_node	*smallest;
	int		la;

	la = ft_lstlen(*a);
	ft_index(*a);
	ft_median(*a);
	smallest = find_smallest(*a);
	if (smallest->index == 0)
		return ;
	else
	{
		if (smallest->above_median)
			full_rra(a, la - smallest->index);
		else
			full_ra(a, smallest->index);
	}
}

t_node	*find_cheap(t_node **b)
{
	t_node	*cheapest;
	t_node	*chain_b;

	chain_b = *b;
	cheapest = chain_b;
	while (chain_b)
	{
		if (chain_b->price < cheapest->price)
			cheapest = chain_b;
		chain_b = chain_b->next;
	}
	return (cheapest);
}

void	set_nodes(t_node **a, t_node **b)
{
	ft_index(*a);
	ft_index(*b);
	ft_median(*a);
	ft_median(*b);
	ft_target(a, b);
	ft_price(a, b);
}

int	push_b(t_node **a, t_node **b)
{
	while (ft_lstlen(*a) > 3)
		pb(a, b);
	return (3);
}

void	push_swap(t_node **a, t_node **b)
{
	int		len_a;
	int		len_b;
	int		i;
	t_node	*smallest;

	i = 0;
	len_a = ft_lstlen(*a);
	if (len_a <= 3)
		tiny_sort(a);
	else
	{
		len_a = push_b(a, b);
		tiny_sort(a);
		len_b = ft_lstlen(*b);
		while (i < len_b)
		{
			set_nodes(a, b);
			set_top(a, b, find_cheap(b));
			pa(a, b);
			i++;
		}
		finish(a);
	}
}
