/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:07 by lauger            #+#    #+#             */
/*   Updated: 2024/01/22 09:55:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


t_list	*arg_to_lst(t_list *head, int ac, char **av);

void	print_lst(const t_list *head);
int		compare_value_list(long long value_compare, t_list *head);
int		check_int(char *s);
int		check_sign(char *s);

void	swap_a(t_list **stack_a);
void	rotate_a(t_list **head);
void	r_rotate_a(t_list **head);
void	pushAtoB(t_list **stackA, t_list **stackB);

void	three_hit(t_list *head);

void	free_content(void *content);


#endif
