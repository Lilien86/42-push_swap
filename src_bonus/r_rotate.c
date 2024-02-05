/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:21:22 by lauger            #+#    #+#             */
/*   Updated: 2024/02/05 13:44:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	r_rotate_cpy(t_list **head);

void	r_rotate_a(t_list **head)
{
	t_list	*last_node;
	t_list	*second_lastnode;

	if (*head != NULL && (*head)->next != NULL)
	{
		last_node = ft_lstlast(*head);
		if (last_node != NULL)
		{
			second_lastnode = *head;
			while (second_lastnode->next != last_node)
				second_lastnode = second_lastnode->next;
			second_lastnode->next = NULL;
			last_node->next = *head;
			*head = last_node;
		}
	}
}

void	r_rotate_b(t_list **head)
{
	t_list	*last_node;
	t_list	*second_lastnode;

	if (*head != NULL && (*head)->next != NULL)
	{
		last_node = ft_lstlast(*head);
		if (last_node != NULL)
		{
			second_lastnode = *head;
			while (second_lastnode->next != last_node)
				second_lastnode = second_lastnode->next;
			second_lastnode->next = NULL;
			last_node->next = *head;
			*head = last_node;
		}
	}
}

static void	r_rotate_cpy(t_list **head)
{
	t_list	*last_node;
	t_list	*second_lastnode;

	if (*head != NULL && (*head)->next != NULL)
	{
		last_node = ft_lstlast(*head);
		if (last_node != NULL)
		{
			second_lastnode = *head;
			while (second_lastnode->next != last_node)
				second_lastnode = second_lastnode->next;
			second_lastnode->next = NULL;
			last_node->next = *head;
			*head = last_node;
		}
	}
}

void	r_rotate_a_b(t_list **head, t_list **second)
{
	r_rotate_cpy(head);
	r_rotate_cpy(second);
}
