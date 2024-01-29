/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:17:54 by lauger            #+#    #+#             */
/*   Updated: 2024/01/29 14:54:49 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_smalest(t_list* head);
int find_bigest(t_list* head);
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
		if (*(int *)(current->content) == value_compare)
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
		ft_printf("\n%d: %d -> \n", i, *(int *)current->content);
		current = current->next;
		i++;
	}
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
	if (stacks.aaa == NULL)
	{
		ft_printf("head = NULL, %p\n", stacks.aaa);
		return 0;
	}

	if (ft_lstsize(stacks.aaa) == 3)
		three_hit(&stacks.aaa);
	else if (ft_lstsize(stacks.aaa) == 5)
		five_hit(&stacks.aaa, &stacks.bbb);
	
	//lst_to_tab
	stacks.nb_elem =  ft_lstsize(stacks.aaa);
	stacks.tab = list_to_array(stacks.aaa, &stacks.nb_elem);
	
	//print tab_to_sort
	ft_sort_int_tab(stacks.tab, stacks.nb_elem);
	//ft_printf("\n");
	//ft_print_tab(stacks.tab, ft_lstsize(stacks.aaa));
	
	//ft_printf("---head----\n");
	//print_lst(stacks.aaa);
	//ft_printf("---second----\n");
	//print_lst(stacks.bbb);
	
	dychotomy(&stacks);
	
	//print final linked_lst
	// ft_printf("---head----\n");
	// print_lst(stacks.aaa);
	// ft_printf("---second----\n");
	// print_lst(stacks.bbb);
	
	while (stacks.bbb)
	{
		move_cheapest(&stacks);
	}

	int smallest_idx = find_smalest(stacks.aaa);
	int i = 0;
	while (i < smallest_idx)
	{
		rotate_a(&stacks.aaa);
		i++;
	}
	
	//print final linked_lst
	// ft_printf("---head----\n");
	// print_lst(stacks.aaa);
	// ft_printf("---second----\n");
	// print_lst(stacks.bbb);
	
	// t_move move;
	// move = test(stacks);
	// ft_printf("value: %d\nmove: %d\n %d\n%d\n", move.target, move.amount_a, move.amount_b, move.total_moves);

	

	free(stacks.tab);
	ft_lstclear(&stacks.aaa, free_content);
	return (0);
}
