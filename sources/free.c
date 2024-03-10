/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:30:55 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:21:20 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_rest(char **str, int ac)
{
	int	i;

	i = 2;
	if (str[i] == NULL)
		return ;
	while (i < ac)
		free(str[i++]);
}

void	ft_free_cat(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_argv(char **str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_check_free(t_node *a, char **str)
{
	free(a);
	ft_free_argv(str);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_all(t_node **a)
{
	t_node	*tmp;
	t_node	*pos;

	if (a == NULL)
		return ;
	pos = *a;
	while (pos)
	{
		tmp = pos->next;
		free(pos);
		pos = tmp;
	}
	*a = NULL;
}
