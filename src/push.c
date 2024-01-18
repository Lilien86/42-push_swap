/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:56:58 by lauger            #+#    #+#             */
/*   Updated: 2024/01/18 13:59:22 by lauger           ###   ########.fr       */
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
}