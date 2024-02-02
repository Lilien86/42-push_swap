/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find_target.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:47:27 by lauger            #+#    #+#             */
/*   Updated: 2024/02/02 13:49:36 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_target(int target, t_stacks *stacks)
{
	t_list	*current;
	int		nb_moves;

	current = stacks->aaa;
	nb_moves = 0;
	while (current)
	{
		if (*(int *)current->content == target)
			return (nb_moves);
		current = current->next;
		nb_moves++;
	}
	return (nb_moves);
}

int	find_target(int nb, t_stacks *stacks)
{
	t_list	*current;
	int		nb_move;
	int		target;

	target = INT_MAX;
	current = stacks->aaa;
	nb_move = 0;
	if (nb > find_value_bigest(stacks->aaa)
		|| nb < find_value_smalest(stacks->aaa))
		return (find_value_smalest(stacks->aaa));
	while (current)
	{
		if (nb < *(int *)current->content)
		{
			if (target > *(int *)current->content)
				target = *(int *)current->content;
		}
		current = current->next;
		nb_move++;
	}
	if (target == INT_MAX)
		return (find_value_smalest(stacks->aaa));
	return (target);
}

int	mediane(t_list *list, int index)
{
	int	mediane;

	mediane = ft_lstsize(list) / 2;
	if (index <= mediane)
		return (1);
	else
		return (2);
}
