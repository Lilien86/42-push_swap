/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:56:58 by lauger            #+#    #+#             */
/*   Updated: 2024/01/23 13:30:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushAtoB(t_list** stackA, t_list** stackB)
{
	t_list	*firstt_listA;

	if (*stackA != NULL)
	{
		firstt_listA = *stackA;
		*stackA = (*stackA)->next;
		if (*stackB == NULL)
		{
			*stackB = firstt_listA;
			(*stackB)->next = NULL;
		} else
		{
			firstt_listA->next = *stackB;
			*stackB = firstt_listA;
		}
	}
	ft_printf("pb\n");
}

void pushBtoA(t_list** stackB, t_list** stackA)
{
	t_list	*firstt_listB;

	if (*stackB != NULL)
	{
		firstt_listB = *stackB;
		*stackB = (*stackB)->next;
		if (*stackA == NULL)
		{
			*stackA = firstt_listB;
			(*stackA)->next = NULL;
		} else
		{
			firstt_listB->next = *stackA;
			*stackA = firstt_listB;
		}
	}
	ft_printf("pa\n");
}