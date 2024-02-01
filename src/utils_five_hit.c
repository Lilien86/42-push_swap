/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_five_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:34:46 by lauger            #+#    #+#             */
/*   Updated: 2024/01/31 13:56:58 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_value_smalest(t_list *head)
{
	t_list	*current;
	int		smalest;

	if (head == NULL)
		return (-1);
	smalest = *(int *)head->content;
	current = head->next;
	while (current != NULL)
	{
		if (*(int *)current->content < smalest)
		{
			smalest = *(int *)current->content;
		}
		current = current->next;
	}
	return (smalest);
}

int	find_value_bigest(t_list *head)
{
	t_list	*current;
	int		bigest;

	if (head == NULL)
		return (-1);
	bigest = *(int *)head->content;
	current = head->next;
	while (current != NULL)
	{
		if (*(int *)current->content > bigest)
		{
			bigest = *(int *)current->content;
		}
		current = current->next;
	}
	return (bigest);
}

int	find_position(t_list *head, int value)
{
	int		position;
	t_list	*current;

	position = 0;
	current = head;
	while (current != NULL)
	{
		if (*(int *)(current->content) == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

int	is_value_in_list(t_list *head, int value)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		if (*(int *)(current->content) == value)
		{
			return (1);
		}
		current = current->next;
	}
	return (0);
}

void	make_up_and_push(int position, t_list **head, t_list **second)
{
	int	i;

	i = 0;
	while (i < position)
	{
		rotate_a(head);
		i++;
	}
	push_a_to_b(head, second);
}
