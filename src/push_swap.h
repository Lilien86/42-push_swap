/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:07 by lauger            #+#    #+#             */
/*   Updated: 2024/01/23 13:30:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_info_lst
{
    int     bigest;
	int     smalest;
	int	    bigest_value;
	int	    smalest_value;
	int     size;
}   t_info_lst;


t_list	*arg_to_lst(t_list *head, int ac, char **av);

void	print_lst(const t_list *head);
int		compare_value_list(long long value_compare, t_list *head);
int		check_int(char *s);
int		check_sign(char *s);

void	swap_a(t_list **stack_a);
void	rotate_a(t_list **head);
void	r_rotate_a(t_list **head);
void	pushAtoB(t_list **stackA, t_list **stackB);
void 	pushBtoA(t_list** stackB, t_list** stackA);

int     find_smalest(t_list *head);
int     find_bigest(t_list *head);
int		is_ascending(t_list *head);

void	three_hit(t_list **head);
void    five_hit(t_list **head, t_list **second);

void	free_content(void *content);


#endif
