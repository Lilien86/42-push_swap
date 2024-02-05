/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:16:26 by lauger            #+#    #+#             */
/*   Updated: 2024/02/05 08:04:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_tab_of_target_2(t_stacks *stacks, t_move *costs, int i)
{
	if (costs[i].med_a == 1)
		costs[i].amount_a = index_of_target(costs[i].target, stacks);
	else
	{
		costs[i].amount_a = ft_lstsize(stacks->aaa)
			- index_of_target(costs[i].target, stacks);
	}
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
}

t_move	*create_tab_of_target(t_stacks *stacks)
{
	//t_list	*curent_a;
	t_list	*curent_b;
	t_move	*costs;
	int		i;

	//curent_a = stacks->aaa;
	curent_b = stacks->bbb;
	i = 0;
	costs = malloc(sizeof(t_move) * ft_lstsize(stacks->bbb));
	while (i < ft_lstsize(stacks->bbb))
	{
		costs[i].target = find_target(*(int *)curent_b->content, stacks);
		costs[i].med_a
			= mediane(stacks->aaa, index_of_target(costs[i].target, stacks));
		costs[i].med_b = mediane(stacks->bbb, i);
		create_tab_of_target_2(stacks, costs, i);
		curent_b = curent_b->next;
		i++;
	}
	return (costs);
}

void	move_cheapest_2(t_stacks *stacks, t_move c)
{
	while ((--c.amount_a >= 0) | (--c.amount_b >= 0))
	{
		if (c.med_a == c.med_b && c.amount_a >= 0 && c.amount_b >= 0)
		{
			if (c.med_a == 1)
				rotate_a_b(&stacks->aaa, &stacks->bbb);
			if (c.med_a == 2)
				r_rotate_a_b(&stacks->aaa, &stacks->bbb);
		}
		else
		{
			if (c.med_a == 1 && c.amount_a >= 0)
				rotate_a(&stacks->aaa);
			if (c.med_a == 2 && c.amount_a >= 0)
				r_rotate_a(&stacks->aaa);
			if (c.med_b == 1 && c.amount_b >= 0)
				rotate_b(&stacks->bbb);
			if (c.med_b == 2 && c.amount_b >= 0)
				r_rotate_b(&stacks->bbb);
		}
	}
}

void	move_cheapest(t_stacks *stacks)
{
	t_move	*costs;
	int		i;
	t_move	c;

	i = 0;
	c.total_moves = INT_MAX;
	costs = create_tab_of_target(stacks);
	while (i < ft_lstsize(stacks->bbb))
	{
		if (costs[i].total_moves < c.total_moves)
			c = costs[i];
		i++;
	}
	move_cheapest_2(stacks, c);
	free(costs);
}
