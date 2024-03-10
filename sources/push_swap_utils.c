/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:22 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:21:37 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstlen(t_node *lst)
{
	struct s_node	*ptr;
	int				i;

	if (lst == NULL)
		return (0);
	ptr = lst->next;
	i = 1;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	ft_target(t_node **a, t_node **b)
{
	t_node	*chain_a;
	t_node	*chain_b;
	long	target_val;

	chain_b = *b;
	while (chain_b)
	{
		target_val = LONG_MAX;
		chain_a = *a;
		while (chain_a)
		{
			if (chain_a-> value > chain_b->value && chain_a->value < target_val)
			{
				target_val = (long)chain_a->value;
				chain_b->target = chain_a;
			}
			chain_a = chain_a->next;
		}
		if (target_val == LONG_MAX)
			chain_b->target = find_smallest(*a);
		chain_b = chain_b->next;
	}
}

void	ft_index(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->index = i;
		i++;
		lst = lst->next;
	}
}

void	ft_median(t_node *lst)
{
	int	median;

	median = ft_lstlen(lst) / 2;
	while (lst)
	{
		if (lst->index <= median - 1)
			lst->above_median = 0;
		else
			lst->above_median = 1;
		lst = lst->next;
	}
}

void	ft_price(t_node **a, t_node **b)
{
	int		la;
	int		lb;
	t_node	*tick_b;

	la = ft_lstlen(*a);
	lb = ft_lstlen(*b);
	tick_b = *b;
	while (tick_b)
	{
		if (tick_b->above_median && tick_b->target->above_median)
			tick_b->price = lb - tick_b->index + la
				- tick_b->target->index;
		else if (!tick_b->above_median && !tick_b->target->above_median)
			tick_b->price = tick_b->index + tick_b->target->index;
		else if (!tick_b->above_median && tick_b->target->above_median)
			tick_b->price = tick_b->index + (la - tick_b->target->index);
		else if (tick_b->above_median && !tick_b->target->above_median)
			tick_b->price = (lb - tick_b->index) + tick_b->target->index;
		tick_b = tick_b->next;
	}
}
