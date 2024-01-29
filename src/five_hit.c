/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:13:27 by marvin            #+#    #+#             */
/*   Updated: 2024/01/29 10:37:46 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_value_smalest(t_list *head)
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

int find_value_bigest(t_list *head)
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

static int	find_position(t_list *head, int value)
{
	int position = 0;
	t_list *current = head;

	while (current != NULL)
	{
		if (*(int *)(current->content) == value)
			return position;
		current = current->next;
		position++;
	}
	return -1;
}

int is_value_in_list(t_list *head, int value)
{
	t_list *current = head;

	while (current != NULL) {
		if (*(int *)(current->content) == value)
		{
			return 1;
		}
		current = current->next;
	}
	return 0;
}

static void make_up_and_push(int position, t_list **head, t_list **second)
{
	int i = 0;
	while (i < position) {
		rotate_a(head);
		i++;
	}
	pushAtoB(head, second);
}

void move_indexfor_end(t_info_lst *info,  t_list **head, t_list **second)
{
	if (info->smalest == info->size)
	{
		r_rotate_a(head);
		pushAtoB(head, second);
		info->size--;
		info->bigest = find_position(*head, info->bigest_value);
		info->smalest = 5;
	}
	else if (info->bigest == info->size)
	{
		r_rotate_a(head);
		pushAtoB(head,second);
		info->size--;
		info->smalest = find_position(*head, info->smalest_value);
		info->bigest = 5;
	}
}

void	move_indexfor_zero(t_info_lst *info,  t_list **head, t_list **second)
{
	if (info->bigest == 0)
	{
		pushAtoB(head, second);
		info->smalest = find_position(*head, info->smalest_value);
		info->bigest = 5;
	}
	else if (info->smalest == 0)
	{
		pushAtoB(head, second);
		info->bigest = find_position(*head, info->bigest_value);
		info->smalest = 5;
	}
}

void    five_hit(t_list **head, t_list **second)
{
	t_info_lst	info;

	info.bigest_value = find_value_bigest(*head);
	info.smalest_value = find_value_smalest(*head);
	info.bigest = find_position(*head, info.bigest_value);
	info.smalest = find_position(*head, info.smalest_value);
	info.size = 4;

	move_indexfor_end(&info, head, second);
	move_indexfor_zero(&info, head, second);
	while (is_value_in_list(*head, info.bigest_value) || is_value_in_list(*head, info.smalest_value))
	{
		info.bigest = find_position(*head, info.bigest_value);
		info.smalest = find_position(*head, info.smalest_value);
		if ((info.bigest <= info.smalest || !is_value_in_list(*head, info.smalest_value)) && is_value_in_list(*head, info.bigest_value))
			make_up_and_push(info.bigest, head, second);
		else if ((info.smalest < info.bigest || !is_value_in_list(*head, info.bigest_value)) && is_value_in_list(*head, info.smalest_value))
			make_up_and_push(info.smalest, head, second);
	}
	three_hit(head);
	pushBtoA(second, head);
	if (is_ascending(*head) == 0)
		rotate_a(head);
	pushBtoA(second, head);
	if (is_ascending(*head) == 0)
		rotate_a(head);
}