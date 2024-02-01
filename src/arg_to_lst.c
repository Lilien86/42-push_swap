/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:20:11 by lauger            #+#    #+#             */
/*   Updated: 2024/02/01 14:09:45 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_add_list(char *arg, t_list **head, char **tab)
{
	long long	nbr;
	int			*ptr;
	t_list		*lst;

	if (check_sign(arg) == -1 || check_int(arg) == -1
		|| compare_value_list(ft_atol(arg), *head) == -1)
	{
		if (*head)
			ft_lstclear(head, free_content);
		if (tab)
			ft_free_tab_str(tab);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("the format is not correct", 2);
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

int	only_space(char *s)
{
	int	len_s;
	int	i;

	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (-1);
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
			ft_free_tab_str(tab_arg);
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("the format is not correct", 2);
			exit(0);
		}
		j = 0;
		while (tab_arg[j] != 0)
			j += check_and_add_list(tab_arg[j], head, tab_arg);
		ft_free_tab_str(tab_arg);
		i++;
	}
}

t_list	*arg_to_lst(t_list *head, int ac, char **av)
{
	managing_arg(ac, av, &head);
	return (head);
}
