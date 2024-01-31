/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:16:26 by lauger            #+#    #+#             */
/*   Updated: 2024/01/31 10:47:01 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
		if (nb < *(int*)current->content)
		{
			if (target > *(int*)current->content)
				target = *(int*)current->content;
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

t_move	*create_tab_of_target(t_stacks *stacks)
{
	t_list	*curent_a;
	t_list	*curent_b;
	t_move	*costs;
	int		i;

	curent_a = stacks->aaa;
	curent_b = stacks->bbb;
	i = 0;
	costs = malloc(sizeof(t_move) * ft_lstsize(stacks->bbb));
	while (i < ft_lstsize(stacks->bbb))
	{	
		costs[i].target = find_target(*(int*)curent_b->content, stacks);
		costs[i].med_a = mediane(stacks->aaa, index_of_target(costs[i].target, stacks));
		costs[i].med_b = mediane(stacks->bbb, i);
		if (costs[i].med_a == 1)
			costs[i].amount_a = index_of_target(costs[i].target, stacks);
		else
			costs[i].amount_a = ft_lstsize(stacks->aaa) - index_of_target(costs[i].target, stacks);
		if (costs[i].med_b == 1)
			costs[i].amount_b = i;
		else
			costs[i].amount_b = ft_lstsize(stacks->bbb) - i;
		if (costs[i].med_a == costs[i].med_b)
		{
			if (costs[i].amount_a < costs[i].amount_b)
				costs[i].total_moves = costs[i].amount_b;
			else
				costs[i].total_moves = costs[i].amount_a;
		}
		else
			costs[i].total_moves = costs[i].amount_a + costs[i].amount_b;
		curent_b = curent_b->next;
		i++;
	}
	return (costs);
}

void	move_cheapest(t_stacks *stacks)
{
	t_move	*costs = create_tab_of_target(stacks);
	int		i;
	t_move	cheapest;

	cheapest.total_moves = INT_MAX;
	i = 0;
	while (i < ft_lstsize(stacks->bbb))
	{
		if (costs[i].total_moves < cheapest.total_moves)
			cheapest = costs[i];
		i++;
	}
	i = 0;
	if (cheapest.med_a == cheapest.med_b)
	{
		if (cheapest.med_a == 1)
		{
			while (i < cheapest.amount_a && i < cheapest.amount_b)
			{
				rotate_a_b(&stacks->aaa, &stacks->bbb);
				i++;
			}
			while (i < cheapest.amount_a)
			{
				rotate_a(&stacks->aaa);
				i++;
			}
			while (i < cheapest.amount_b)
			{
				rotate_b(&stacks->bbb);
				i++;
			}
		}
		else
		{
			while (i < cheapest.amount_a && i < cheapest.amount_b)
			{
				r_rotate_a_b(&stacks->aaa, &stacks->bbb);
				i++;
			}
			while (i < cheapest.amount_a)
			{
				r_rotate_a(&stacks->aaa);
				i++;
			}
			while (i < cheapest.amount_b)
			{
				r_rotate_b(&stacks->bbb);
				i++;
			}
		}
	}
	else if (cheapest.med_a != cheapest.med_b)
	{
		if (cheapest.med_a == 1)
		{
			while (i < cheapest.amount_a)
			{
				rotate_a(&stacks->aaa);
				i++;
			}
		}
		else
		{
			while (i < cheapest.amount_a)
			{
				r_rotate_a(&stacks->aaa);
				i++;
			}
		}
		i = 0;
		if (cheapest.med_b == 1)
		{
			while (i < cheapest.amount_b)
			{
				rotate_b(&stacks->bbb);
				i++;
			}
		}
		else
		{
			while (i < cheapest.amount_b)
			{
				r_rotate_b(&stacks->bbb);
				i++;
			}
		}
	}
}