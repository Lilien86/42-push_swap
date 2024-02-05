/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:26:26 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 10:26:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:20:11 by lauger            #+#    #+#             */
/*   Updated: 2024/02/05 09:57:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_modif_list(char *arg, t_stacks *stacks, char **tab)
{
	if (check_is_move(arg) == 0)
	{
		if (stacks->aaa)
			ft_lstclear(&stacks->aaa, free_content);
		ft_free_tab_str(tab);
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	else
	{
		to_do_movement(arg, stacks);
	}
	return (1);
}

/*static int	only_space(char *s)
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
}*/

static void	managing_arg(int ac, char **av, t_stacks *stacks, int index)
{
	int		i;
	int		j;
	char	**tab_arg;

	i = index;
	while (i < ac)
	{
		tab_arg = ft_split(av[i], ' ');
		if (tab_arg == NULL || tab_arg[0] == 0)
		{
			if (stacks->aaa)
				ft_lstclear(&stacks->aaa, free_content);
			ft_free_tab_str(tab_arg);
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("the format is not correct", 2);
			exit(0);
		}
		j = 0;
		while (tab_arg[j] != 0)
		{
			j += check_modif_list(tab_arg[j], stacks, tab_arg);
		}
		ft_free_tab_str(tab_arg);
		i++;
	}
}

void	move_to_lst(t_stacks *stacks, int ac, char **av)
{
    int i = 1;
    while (i < ac)
    {
        char first_char = av[i][0];

        if (first_char == 'r' || first_char == 's' || first_char == 'p')
        {
			break;
        }
        else
        	i++;
    }
	managing_arg(ac, av, stacks, i);
}
