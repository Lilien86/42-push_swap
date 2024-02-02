/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_algorythme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:10:01 by lauger            #+#    #+#             */
/*   Updated: 2024/02/02 16:12:28 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	multi_hit(t_stacks *stacks)
{
	stacks->nb_elem = ft_lstsize(stacks->aaa);
	stacks->tab = list_to_array(stacks->aaa, &stacks->nb_elem);
	ft_sort_int_tab(stacks->tab, stacks->nb_elem);
	dychotomy(stacks);
	while (stacks->bbb)
	{
		move_cheapest(stacks);
		push_b_to_a(&stacks->bbb, &stacks->aaa);
	}
	while (*(int *)stacks->aaa->content != find_value_smalest(stacks->aaa))
	{
		if (find_smalest(stacks->aaa) <= ft_lstsize(stacks->aaa) / 2)
			rotate_a(&stacks->aaa);
		if (find_smalest(stacks->aaa) > ft_lstsize(stacks->aaa) / 2)
			r_rotate_a(&stacks->aaa);
	}
}

void	find_algorythme(t_stacks *stacks)
{
	if (ft_lstsize(stacks->aaa) <= 3)
		three_hit(&stacks->aaa);
	else if (ft_lstsize(stacks->aaa) <= 5)
		five_hit(&stacks->aaa, &stacks->bbb);
	else
		multi_hit(stacks);
}
