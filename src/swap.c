/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:42:40 by lauger            #+#    #+#             */
/*   Updated: 2024/01/19 13:58:42 by lauger           ###   ########.fr       */
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
	ft_printf("sa\n");
}
/*
void swap_b(Node **stack_b)
{
	swap_a(stack_b);
	ft_printf("sb\n");
}

void swap_both(Node **stack_a, Node **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_printf("ss\n");
}*/








