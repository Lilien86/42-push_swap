/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:25:16 by lauger            #+#    #+#             */
/*   Updated: 2024/01/23 12:46:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_bigest(t_list* head)
{
	t_list*	current;
	int		bigest;
	int		position;
	int 	current_position;

	if (head == NULL)
		return -1;
	bigest = *(int *)head->content;
	position = 0;
	current_position = 0;
	current = head->next;
	while (current != NULL)
	{
		current_position++;
		if (*(int *)current->content > bigest)
		{
			bigest = *(int *)current->content;
			position = current_position;
		}
		current = current->next;
	}	
	return (position);
}

int find_smalest(t_list* head)
{
	t_list*	current;
	int		smalest;
	int		position;
	int 	current_position;

	if (head == NULL)
		return -1;
	smalest = *(int *)head->content;
	position = 0;
	current_position = 0;
	current = head->next;
	while (current != NULL)
	{
		current_position++;
		if (*(int *)current->content < smalest)
		{
			smalest = *(int *)current->content;
			position = current_position;
		}
		current = current->next;
	}	
	return (position);
}

int	is_ascending(t_list *head)
{
	t_list	*current;
	current = head;
	while (current != NULL && current->next != NULL)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return 1;
}


void	three_hit(t_list **head)
{
	int	bigest;
	int	smalest;

	bigest = find_bigest(*head);
	smalest = find_smalest(*head);
	if (is_ascending(*head) == 1)
		return ;
	while (is_ascending(*head) == 0)
	{
		bigest = find_bigest(*head);
		smalest = find_smalest(*head);
		if (bigest > smalest)
			swap_a(head);
		else if (bigest < smalest)
			rotate_a(head);
	}
	//print_lst(head);
}