/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:10 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 10:23:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void    init_var(t_stacks *elem)
{
    elem->aaa = NULL;
    elem->bbb = NULL;
    elem->tab = NULL;
    elem->nb_elem = 0;
    
}

int main(int ac, char **av)
{
    t_stacks *elem;
    
    elem = (t_stacks *)malloc(sizeof(t_stacks));
    if (elem == NULL)
    {
        ft_putendl_fd("Error", 2);
        return 1;
    }
    init_var(elem);
    elem->aaa = arg_to_lst(elem->aaa, ac, av);
	if (elem->aaa == NULL)
        return 0;
	
	elem->nb_elem = ft_lstsize(elem->aaa);
	print_lst(elem->aaa);
	move_to_lst(elem,ac, av);
    print_lst(elem->aaa);
	if (is_ascending(elem->aaa) == 1 && elem->nb_elem == ft_lstsize(elem->aaa))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
    if (elem->aaa)
		ft_lstclear(&elem->aaa, free_content);
    if (elem->bbb)
		ft_lstclear(&elem->bbb, free_content);
	if (elem)
		free(elem);

    free(elem);

    return 0;
}

