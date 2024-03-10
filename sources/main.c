/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:11 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 14:32:06 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_node *lst)
{
	while (lst && lst->next)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		i;
	char	*join;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc == 1 || !argv[1][0])
		return (0);
	if (argc > 2)
	{
		argv[1] = ft_reorg(argv, argc);
		argc = 2;
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&a, argv);
	if (!is_sorted(a))
		push_swap(&a, &b);
	ft_free_all(&a);
	return (0);
}
