/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:13:27 by marvin            #+#    #+#             */
/*   Updated: 2024/01/31 13:40:58 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_index_for_end(t_info_lst *info, t_list **head, t_list **second)
{
	if (info->smalest == info->size)
	{
		r_rotate_a(head);
		push_a_to_b(head, second);
		info->size--;
		info->bigest = find_position(*head, info->bigest_value);
		info->smalest = 5;
	}
	else if (info->bigest == info->size)
	{
		r_rotate_a(head);
		push_a_to_b(head, second);
		info->size--;
		info->smalest = find_position(*head, info->smalest_value);
		info->bigest = 5;
	}
}

void	move_indexfor_zero(t_info_lst *info, t_list **head, t_list **second)
{
	if (info->bigest == 0)
	{
		push_a_to_b(head, second);
		info->smalest = find_position(*head, info->smalest_value);
		info->bigest = 5;
	}
	else if (info->smalest == 0)
	{
		push_a_to_b(head, second);
		info->bigest = find_position(*head, info->bigest_value);
		info->smalest = 5;
	}
}

void	five_hit(t_list **head, t_list **second)
{
	t_info_lst	info;

	info.bigest_value = find_value_bigest(*head);
	info.smalest_value = find_value_smalest(*head);
	info.bigest = find_position(*head, info.bigest_value);
	info.smalest = find_position(*head, info.smalest_value);
	info.size = 4;
	move_index_for_end(&info, head, second);
	move_indexfor_zero(&info, head, second);
	while (is_value_in_list(*head, info.bigest_value)
		|| is_value_in_list(*head, info.smalest_value))
	{
		info.bigest = find_position(*head, info.bigest_value);
		info.smalest = find_position(*head, info.smalest_value);
		if ((info.bigest <= info.smalest || !is_value_in_list(*head,
			info.smalest_value)) && is_value_in_list(*head, info.bigest_value))
			make_up_and_push(info.bigest, head, second);
		else if ((info.smalest < info.bigest || !is_value_in_list(*head,
			info.bigest_value)) && is_value_in_list(*head, info.smalest_value))
			make_up_and_push(info.smalest, head, second);
	}
	three_hit(head);
	push_b_to_a(second, head);
	if (is_ascending(*head) == 0)
		rotate_a(head);
	push_b_to_a(second, head);
	if (is_ascending(*head) == 0)
		rotate_a(head);
}
