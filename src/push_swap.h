/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:07 by lauger            #+#    #+#             */
/*   Updated: 2024/02/01 10:10:45 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
#include <limits.h>

typedef struct s_info_lst
{
	int		bigest;
	int		smalest;
	int		bigest_value;
	int		smalest_value;
	int		size;
}	t_info_lst;

typedef struct s_stacks
{
	t_list		*aaa;
	t_list		*bbb;
	int			*tab;
	int			nb_elem;
}	t_stacks;

typedef struct s_move
{
	int			target;
	int			amount_a;
	int			amount_b;
	int			med_a;
	int			med_b;
	int			total_moves;
}	t_move;

t_list	*arg_to_lst(t_list *head, int ac, char **av);

//##############
//MOOOOOOOOOVE
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);

void	rotate_a(t_list **head);
void	rotate_b(t_list **head);
void	rotate_a_b(t_list **aaa, t_list **bbb);
void	r_rotate_b(t_list **head);
void	r_rotate_a(t_list **head);
void	r_rotate_a_b(t_list **head, t_list **second);

void	push_a_to_b(t_list **stack_a, t_list **stack_b);
void	push_b_to_a(t_list **stack_b, t_list **stack_a);
//END MOOOOV
//#############

//######
//UTILS
int		find_smalest(t_list *head);
int		find_bigest(t_list *head);
int		find_value_smalest(t_list *head);
int		find_value_bigest(t_list *head);
int		is_value_in_list(t_list *head, int value);
int		find_position(t_list *head, int value);
int		is_ascending(t_list *head);
int		*list_to_array(t_list *head, int *size);
void	free_content(void *content);
void	print_lst(const t_list *head);
int		compare_value_list(long long value_compare, t_list *head);
void	make_up_and_push(int position, t_list **head, t_list **second);
int		check_int(char *s);
int		check_sign(char *s);
//END UTILS
//#########

void	three_hit(t_list **head);
void	five_hit(t_list **head, t_list **second);
void	dychotomy(t_stacks *stacks);
t_move	*create_tab_of_target(t_stacks *stacks);
void	move_cheapest(t_stacks *stacks);
void	find_algorythme(t_stacks stacks);

#endif
