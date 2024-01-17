/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:17:54 by lauger            #+#    #+#             */
/*   Updated: 2024/01/17 13:26:36 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (!((s[i] >= '0' && s[i] <= '9')
			|| s[i] == '-' || s[i] == '+'))
			return (-1);
		i++;
	}
	if (ft_atol(s)  > 2147483647 || ft_atol(s) < -2147483648)
		return (-1);

	return (0);
}

int compare_value_list(long long value_compare, t_list *head)
{
	t_list		*current;

	current = head;
	while (current != NULL)
	{
		if ((long long)current->content == value_compare)
			return (-1);
		current = current->next;
	}
	return 0;
}

void print_lst(const t_list *head)
{
	const t_list *current = head;
	int i = 0;
	while (current != NULL)
	{
		ft_printf("\n%d: %d -> \n", i, (int *)current->content);
		current = current->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	/*t_list	*head;
	char	**tab_arg;
	int		i;

	head = NULL;
	i = 1;
	while (i < ac)
	{
		tab_arg = ft_split(av[i], ' ');
		if (tab_arg == NULL || tab_arg[0] == 0)
		{
			ft_free_lst(head);
			ft_printf("Error:\nthe format is not correct\n");
			exit(0);
		}
		int j = 0;
		while (tab_arg[j] != NULL)
		{
			if (check_sign(tab_arg[j]) == -1 || check_int(tab_arg[j]) == -1 ||
				compare_value_list(ft_atol(tab_arg[j]), head) == -1)
			{
				ft_free_tab(tab_arg);
				ft_free_lst(head);
				ft_printf("Error:\nthe format is not correct\n");
				exit(0);
			}
			else
				ft_lstadd_back((t_list**)&head, ft_lstnew((void*)ft_atol(tab_arg[j])));
			j++;
		}
		ft_free_tab(tab_arg);
		i++;
	}
	print_lst(head);
	ft_free_lst(head);*/
	arg_to_lst(ac, av);
	
	return (0);
}
