/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:52:00 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 12:52:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    to_do_movement(char *s, t_stacks *stacks)
{
    if ((ft_strcmp(s, "sa") == 0)) 
        swap_a(&stacks->aaa);
    if ((ft_strcmp(s, "sb") == 0)) 
        swap_b(&stacks->bbb);
    if ((ft_strcmp(s, "ra") == 0)) 
        rotate_a(&stacks->aaa);
    if ((ft_strcmp(s, "rb") == 0)) 
        rotate_b(&stacks->bbb);
    if ((ft_strcmp(s, "rr") == 0)) 
        rotate_a_b(&stacks->aaa, &stacks->bbb);
    if ((ft_strcmp(s, "pa") == 0)) 
        push_b_to_a(&stacks->bbb, &stacks->aaa);
    if ((ft_strcmp(s, "pb") == 0)) 
        push_a_to_b(&stacks->aaa, &stacks->bbb);
    if ((ft_strcmp(s, "rra") == 0)) 
        r_rotate_a(&stacks->aaa);
    if ((ft_strcmp(s, "rrb") == 0)) 
        r_rotate_b(&stacks->bbb);
    if ((ft_strcmp(s, "rrr") == 0)) 
        r_rotate_a_b(&stacks->aaa, &stacks->bbb);
}