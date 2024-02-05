/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:07 by lauger            #+#    #+#             */
/*   Updated: 2024/02/05 13:47:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <limits.h>

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

//check_arg
int		check_sign(char *s);
int		check_int(char *s);
int		compare_value_list(long long value_compare, t_list *head);
int		check_is_move(char *s);

//converssion arg to lst
t_list	*arg_to_lst(t_list *head, int ac, char **av);
void	move_to_lst(t_stacks *stacks, int ac, char **av);

//utils
void	free_content(void *content);
void	print_lst(t_list *head);
void	print_lst_str(t_list *head);
void    to_do_movement(char *s, t_stacks *stacks);
int		ft_strcmp(const char *s1, const char *s2);
int		is_ascending(t_list *head);

//##############
//MOOOOOOOOOVE
void    swap_a(t_list **stack_a);
void    swap_b(t_list **stack_b);
void    swap_a_b(t_list **stack_a, t_list **stack_b);

void    rotate_a(t_list **head);
void    rotate_b(t_list **head);
void    rotate_a_b(t_list **aaa, t_list **bbb);
void    r_rotate_b(t_list **head);
void    r_rotate_a(t_list **head);
void    r_rotate_a_b(t_list **head, t_list **second);

void    push_a_to_b(t_list **stack_a, t_list **stack_b);
void    push_b_to_a(t_list **stack_b, t_list **stack_a);

#endif
