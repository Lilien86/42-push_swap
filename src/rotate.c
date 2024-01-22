/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:00:40 by lauger            #+#    #+#             */
/*   Updated: 2024/01/22 11:11:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void rotate_a(t_list **head)
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
	ft_printf("ra\n");
}*/

void rotate_a(t_list **head)
{
 	t_list *temp;
    int firstValue;

    if (*head != NULL && (*head)->next != NULL)
    {
        // Sauvegarde de la valeur du premier nœud
        firstValue = *((int*)((*head)->content));

        // Déplacement des valeurs
        temp = *head;
        while (temp->next != NULL)
        {
            *((int*)(temp->content)) = *((int*)((temp->next)->content));
            temp = temp->next;
        }

        // Affectation de la première valeur au dernier nœud
        *((int*)(temp->content)) = firstValue;
    }
    ft_printf("ra\n");
}
/*
void rotate_b(t_list **head)
{
	rotate_a(head);
	ft_printf("rb\n");
}

void rotate_a_b(t_list **head)
{
	rotate_a(head);
	rotate_a(head);
	ft_printf("rr\n");
}*/
