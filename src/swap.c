/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:42:40 by lauger            #+#    #+#             */
/*   Updated: 2024/01/31 13:19:31 by lauger           ###   ########.fr       */
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

void	swap_b(t_list **stack_b)
{
	int	*temp;

	temp = NULL;
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp = (int *)(*stack_b)->content;
		(*stack_b)->content = (*stack_b)->next->content;
		(*stack_b)->next->content = temp;
	}
	ft_printf("sb\n");
}

static void	swap_cpy(t_list **stack)
{
	int	*temp;

	temp = NULL;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (int *)(*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap_cpy(stack_a);
	swap_cpy(stack_b);
	ft_printf("ss\n");
}
