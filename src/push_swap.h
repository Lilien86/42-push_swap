/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:07:07 by lauger            #+#    #+#             */
/*   Updated: 2024/01/18 14:02:10 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


t_list	*arg_to_lst(int ac, char **av);

void	print_lst(const t_list *head);
int		compare_value_list(long long value_compare, t_list *head);
int		check_int(char *s);
int		check_sign(char *s);

void	swap_a(t_list **stack_a);
void	rotate_a(t_list **head);
void	r_rotate_a(t_list **head);
void	pushAtoB(t_list **stackA, t_list **stackB);


#endif
