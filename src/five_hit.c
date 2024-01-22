/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:13:27 by marvin            #+#    #+#             */
/*   Updated: 2024/01/22 11:13:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_value_smalest(t_list* head)
{
	t_list*	current;
	int		smalest;

	if (head == NULL)
		return -1;
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

static int find_value_bigest(t_list* head)
{
	t_list*	current;
	int		bigest;
	if (head == NULL)
		return -1;
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

static void		make_up_and_push(t_info_lst info, t_list *head, t_list *second)
{
	int	i;

	i = 0;
	if (find_value_bigest(head) == info.bigest_value && info.bigest < info.smalest)
	{
		while (i < info.bigest)
		{
			i++;
			rotate_a(&head);
			info.bigest--;
		}
		pushAtoB(&head, &second);
	}
	else if (find_value_smalest(head) == info.smalest_value)
	{
		while (i < info.smalest)
		{
			i++;
			rotate_a(&head);
		}
		pushAtoB(&head, &second);
	}
}

void    five_hit(t_list *head, t_list *second)
{
	t_info_lst	info;

	info.bigest = find_bigest(head);
	info.smalest = find_smalest(head);
	info.bigest_value = find_value_bigest(head);
	info.smalest_value = find_value_smalest(head);
	info.size = 4;

	while (info.bigest == 0 || info.smalest == 0)
	{
		pushAtoB(&head, &second);
		info.bigest = find_bigest(head);
		info.smalest = find_smalest(head);
	}
	while (info.bigest == info.size || info.smalest == info.size)
	{
		r_rotate_a(&head);
		pushAtoB(&head, &second);
		if (find_value_bigest(head) == info.bigest_value)
			info.bigest = find_bigest(head);
		if (find_value_smalest(head) == info.smalest_value)
			info.smalest = find_smalest(head);
		info.size--;
	}
	make_up_and_push(info, head, second);
	print_lst(head);
	print_lst(second);
}