/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:17:54 by lauger            #+#    #+#             */
/*   Updated: 2024/01/18 14:04:42 by lauger           ###   ########.fr       */
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
	t_list	*head;
	t_list	*second;
	
	head = arg_to_lst(ac, av);
	print_lst(head);
	second = NULL;
	if (head->next == NULL)
	{
		ft_free_lst(head);
		ft_printf("%p\nHEAD = NULL\n", head->next);
		return (0);
	}
	write (1, "\n", 1);

	rotate_a(&head);
	swap_a(&head);
	r_rotate_a(&head);
	pushAtoB(&head, &second);
	
	print_lst(head);
	print_lst(second);

	ft_free_lst(head);
	return (0);
}
