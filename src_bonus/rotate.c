/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:00:40 by lauger            #+#    #+#             */
/*   Updated: 2024/02/05 13:44:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_a(t_list **head)
{
	t_list	*temp;
	int		first_value;

	if (*head != NULL && (*head)->next != NULL)
	{
		first_value = *((int *)((*head)->content));
		temp = *head;
		while (temp->next != NULL)
		{
			*((int *)(temp->content)) = *((int *)((temp->next)->content));
			temp = temp->next;
		}
		*((int *)(temp->content)) = first_value;
	}
}

void	rotate_b(t_list **head)
{
	t_list	*temp;
	int		first_value;

	if (*head != NULL && (*head)->next != NULL)
	{
		first_value = *((int *)((*head)->content));
		temp = *head;
		while (temp->next != NULL)
		{
			*((int *)(temp->content)) = *((int *)((temp->next)->content));
			temp = temp->next;
		}
		*((int *)(temp->content)) = first_value;
	}
}

static void	rotate_cpy(t_list **head)
{
	t_list	*temp;
	int		first_value;

	if (*head != NULL && (*head)->next != NULL)
	{
		first_value = *((int *)((*head)->content));
		temp = *head;
		while (temp->next != NULL)
		{
			*((int *)(temp->content)) = *((int *)((temp->next)->content));
			temp = temp->next;
		}
		*((int *)(temp->content)) = first_value;
	}
}

void	rotate_a_b(t_list **aaa, t_list **bbb)
{
	rotate_cpy(aaa);
	rotate_cpy(bbb);
}
