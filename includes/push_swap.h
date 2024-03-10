/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndessard <ndessard@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:31:30 by ndessard          #+#    #+#             */
/*   Updated: 2024/02/09 13:38:48 by ndessard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				above_median;
	int				price;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

//	free.c	//
void			ft_free_rest(char **str, int ac);
void			ft_free_cat(char *str);
void			ft_free_argv(char **str);
void			ft_check_free(t_node *a, char **str);
void			ft_free_all(t_node **a);

//	ft_split.c -- ft_split_utils.c	//
char			**ft_split(char const *s, char c);
unsigned int	ft_chain_len(char const *s, char c);
char			**ft_free(char **ptr);
void			*ft_calloc(size_t count, size_t size);

//	full_rot.c -- rotate.c -- rev_rotate.c	//
void			full_ra(t_node **a, int pos);
void			full_rra(t_node **a, int pos);
void			full_rb(t_node **b, int pos);
void			full_rrb(t_node **b, int pos);
void			ra(t_node **a);
void			rb(t_node **b);
void			rr(t_node **a, t_node **b);
void			rra(t_node **a);
void			rrb(t_node **b);
void			rrr(t_node **a, t_node **b);

//	init_stack.c -- init_stack_utils.c	//
void			init_stack(t_node **a, char **argv);
t_node			*find_last_node(t_node *lst);
char			*ft_reorg(char **argv, int argc);
size_t			ft_strlen(char *str);
char			*strjoin(char *s1, char *s2);

//	push_swap.c -- push_swap_utils.c -- push_swap_utils2.c	//
void			finish(t_node **a);
t_node			*find_cheap(t_node **b);
void			set_nodes(t_node **a, t_node **b);
void			set_top(t_node **a, t_node **b, t_node *cheapest);
int				push_b(t_node **a, t_node **b);
void			push_swap(t_node **a, t_node **b);
int				ft_lstlen(t_node *lst);
void			ft_target(t_node **a, t_node **b);
void			ft_index(t_node *lst);
void			ft_median(t_node *lst);
void			ft_price(t_node **a, t_node **b);
t_node			*find_smallest(t_node *lst);
void			prependnode(t_node **lst, t_node *new);

//	push.c -- swap.c	//
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);
void			sa(t_node **a);
void			sb(t_node **b);
void			ss(t_node **a, t_node **b);

//	tiny_sort.c	//
void			tiny_sort(t_node **a);

//  top_rot.c   //
void			top_rr(t_node **a, t_node **b, int pos);
void			top_rrr(t_node **a, t_node **b, int pos);
void			rr_bmedian(t_node **a, t_node **b, t_node *cheapest);
void			rrr_amedian(t_node **a, t_node **b, t_node *cheapest);
