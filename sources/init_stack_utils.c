/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:06 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:21:28 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_last_node(t_node *lst)
{
	t_node	*last;

	last = lst;
	if (last == NULL)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*red_strjoin(char *s1, char *s2, size_t len1, size_t len2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	join = malloc(len1 + len2 + 1);
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	while (++i < len1)
		join[i] = s1[i];
	while (++j < len2)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (join);
}

char	*strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	len2 = ft_strlen(s2);
	join = red_strjoin(s1, s2, len1, len2);
	if (s1)
		free(s1);
	return (join);
}

char	*ft_reorg(char **argv, int argc)
{
	int		i;
	char	*cat;

	i = 1;
	cat = NULL;
	while (i < argc)
	{
		cat = strjoin(cat, argv[i]);
		if (cat == NULL)
			ft_free_cat(cat);
		cat = strjoin(cat, " ");
		if (cat == NULL)
			ft_free_cat(cat);
		i++;
	}
	return (cat);
}
