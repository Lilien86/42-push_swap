/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:28:25 by lauger            #+#    #+#             */
/*   Updated: 2024/01/17 10:52:47 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_add_list(char *arg, t_list **head, char **tab)
{
	long long	nbr;
	int			*ptr;
	t_list		*lst;

	if (check_sign(arg) == -1 || check_int(arg) == -1 || compare_value_list(ft_atol(arg), *head) == -1)
	{
		if (*head)	
			ft_lstclear(head, free_content);
		if (tab)
			ft_free_tab(tab);
		ft_printf("Error:\nthe format is not correct\n");
		exit(0);
	}
	else
	{
		nbr = ft_atol(arg);
		ptr = malloc(sizeof(int));
		*ptr = (int)nbr;
		lst = ft_lstnew(ptr);
		ft_lstadd_back(head, lst);
	}
	return (1);
}

void	managing_arg(int ac, char **av, t_list **head)
{
	int		i;
	int		j;
	char	**tab_arg;

	i = 1;
	while (i < ac)
	{
		tab_arg = ft_split(av[i], ' ');
		if (tab_arg == NULL || tab_arg[0] == 0)
		{
			if (*head)
				ft_lstclear(head, free_content);
			if (tab_arg)
				ft_free_tab(tab_arg);
			ft_printf("Error:\nthe format is not correct\n");
			exit(0);
		}
		j = 0;
		while (tab_arg[j] != 0)
			j += check_and_add_list(tab_arg[j], head, tab_arg);
		ft_free_tab(tab_arg);
		i++;
	}
}

t_list	*arg_to_lst(t_list *head, int ac, char **av)
{
	managing_arg(ac, av, &head);
	//ft_lstclear(&head, free_content);
	return (head);
	
}