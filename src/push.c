/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:56:58 by lauger            #+#    #+#             */
/*   Updated: 2024/01/31 13:24:38 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*firstt_list_a;

	if (*stack_a != NULL)
	{
		firstt_list_a = *stack_a;
		*stack_a = (*stack_a)->next;
		if (*stack_b == NULL)
		{
			*stack_b = firstt_list_a;
			(*stack_b)->next = NULL;
		}
		else
		{
			firstt_list_a->next = *stack_b;
			*stack_b = firstt_list_a;
		}
	}
	ft_printf("pb\n");
}

void	push_b_to_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*firstt_list_b;

	if (*stack_b != NULL)
	{
		firstt_list_b = *stack_b;
		*stack_b = (*stack_b)->next;
		if (*stack_a == NULL)
		{
			*stack_a = firstt_list_b;
			(*stack_a)->next = NULL;
		}
		else
		{
			firstt_list_b->next = *stack_a;
			*stack_a = firstt_list_b;
		}
	}
	ft_printf("pa\n");
}
