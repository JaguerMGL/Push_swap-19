/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:46 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:21:47 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_sort(t_node **a)
{
	t_node	*last;

	last = find_last_node(*a);
	if ((*a)->value > (*a)->next->value && (*a)->value > last->value)
		ra(a);
	else if ((*a)->next->value > (*a)->value && (*a)->next->value > last->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
