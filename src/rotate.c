/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:00:40 by lauger            #+#    #+#             */
/*   Updated: 2024/01/31 13:14:59 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
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
	ft_printf("rr\n");
}
