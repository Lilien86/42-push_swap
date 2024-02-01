/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:17:54 by lauger            #+#    #+#             */
/*   Updated: 2024/02/01 15:03:58 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smalest(t_list *head);
int	find_bigest(t_list *head);
int	is_ascending(t_list *head);

int	check_sign(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '+' || s[i] == '-')
			cnt++;
		i++;
	}
	if (cnt > 1)
		return (-1);
	else
		return (0);
}

int	check_int(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!((s[i] >= '0' && s[i] <= '9') || (s[i] == '+' || s[i] == '-')))
			return (-1);
		if (i != 0 && (s[i] == '+' || s[i] == '-')
			&& (s[i - 1] >= '0' && s[i - 1] <= '9'))
			return (-1);
		if (ft_strlen(s) == 1 && (s[0] == '+' || s[0] == '-'))
			return (-1);
		i++;
	}
	if (ft_atol(s) > 2147483647 || ft_atol(s) < -2147483648)
		return (-1);
	return (0);
}

int	compare_value_list(long long value_compare, t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		if (*(int *)(current->content) == value_compare)
			return (-1);
		current = current->next;
	}
	return (0);
}

void	free_content(void *content)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.aaa = NULL;
	stacks.bbb = NULL;
	stacks.aaa = arg_to_lst(stacks.aaa, ac, av);
	stacks.tab = 0;
	if (stacks.aaa == NULL)
		return (0);
	if (is_ascending(stacks.aaa))
	{
		ft_lstclear(&stacks.aaa, free_content);
		return (0);
	}
	find_algorythme(stacks);
	free(stacks.tab);
	if (stacks.aaa)
		ft_lstclear(&stacks.aaa, free_content);
	if (stacks.bbb)
		ft_lstclear(&stacks.bbb, free_content);
	return (0);
}
