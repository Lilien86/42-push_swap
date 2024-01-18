/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:00:40 by lauger            #+#    #+#             */
/*   Updated: 2024/01/18 13:13:51 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_list **head)
{
	t_list	*firstNode;
	t_list	*temp;

	if (*head != NULL && (*head)->next != NULL)
	{
		firstNode = *head;
		*head = (*head)->next;
		firstNode->next = NULL;

		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = firstNode;
	}
}
/*
void rotate_b(t_list **head)
{
	rotate_a(head);
}

void rotate_a_b(t_list **head)
{
	rotate_a(head);
	rotate_a(head);
}*/
