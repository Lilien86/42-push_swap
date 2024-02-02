/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dichotomy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:22:18 by lauger            #+#    #+#             */
/*   Updated: 2024/02/02 14:13:17 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int nb, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->nb_elem)
	{
		if (nb == stacks->tab[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	type_of_placement(int index, t_stacks *stacks)
{
	if (index <= (stacks->nb_elem / 4))
		return (1);
	else if (index < (stacks->nb_elem / 2))
		return (2);
	else if (index < (stacks->nb_elem / 4) * 3)
		return (3);
	else
		return (4);
	return (0);
}

void	dychotomy_2(t_stacks *stacks, int i, int quarter, int type_placement)
{
	if (ft_lstsize(stacks->aaa) == 3)
	{
		three_hit(&stacks->aaa);
		return ;
	}
	if (i > stacks->nb_elem)
		quarter = 4;
	if (type_placement == quarter - 1)
	{
		push_a_to_b(&stacks->aaa, &stacks->bbb);
		rotate_b(&stacks->bbb);
	}
	else if (type_placement == quarter)
	{
		push_a_to_b(&stacks->aaa, &stacks->bbb);
	}
	else
		rotate_a(&stacks->aaa);
}

void	dychotomy(t_stacks *stacks)
{
	t_list	*current;
	int		type_placement;
	int		index;
	int		i;
	int		quarter;

	i = 0;
	quarter = 2;
	while (i < (stacks->nb_elem + stacks->nb_elem / 2))
	{
		current = stacks->aaa;
		index = find_index(*(int *)current->content, stacks);
		type_placement = type_of_placement(index, stacks);
		dychotomy_2(stacks, i, quarter, type_placement);
		i++;
	}
}
