/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:42:40 by lauger            #+#    #+#             */
/*   Updated: 2024/01/17 14:06:54 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int	*temp;
	
	temp = NULL;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = (int *)(*stack_a)->content;
        (*stack_a)->content = (*stack_a)->next->content;
        (*stack_a)->next->content = temp;
	}
}
/*
void swap_b(Node **stack_b)
{
	swap_a(stack_b);
}

void swap_both(Node **stack_a, Node **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}*/








