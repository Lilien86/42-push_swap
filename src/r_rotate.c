/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:21:22 by lauger            #+#    #+#             */
/*   Updated: 2024/01/30 10:58:09 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void r_rotate_cpy(t_list **head);

void r_rotate_a(t_list **head)
{
	t_list	*lastNode;
	t_list	*secondLastNode;

	if (*head != NULL && (*head)->next != NULL)
	{
		lastNode = ft_lstlast(*head);
		if (lastNode != NULL)
		{
			secondLastNode = *head;
			while (secondLastNode->next != lastNode)
				secondLastNode = secondLastNode->next;
			secondLastNode->next = NULL;
			lastNode->next = *head;
			*head = lastNode;
		}
	}
	ft_printf("rra\n");
}

void r_rotate_b(t_list** head)
{
	r_rotate_cpy(head);
	ft_printf("rrb\n");
}

static void r_rotate_cpy(t_list **head)
{
	t_list	*lastNode;
	t_list	*secondLastNode;

	if (*head != NULL && (*head)->next != NULL)
	{
		lastNode = ft_lstlast(*head);
		if (lastNode != NULL)
		{
			secondLastNode = *head;
			while (secondLastNode->next != lastNode)
				secondLastNode = secondLastNode->next;
			secondLastNode->next = NULL;
			lastNode->next = *head;
			*head = lastNode;
		}
	}
}

void r_rotate_a_b(t_list **head, t_list **second)
{
	r_rotate_cpy(head);
	r_rotate_cpy(second);
	ft_printf("rrr\n");
}