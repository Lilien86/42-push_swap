/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:07:19 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 10:07:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_ascending(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL && current->next != NULL)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_content(void *content)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
}

void print_lst(t_list *head)
{
    t_list    *current;
    int       i;

    current = head;
    i = 0;
    while (current != NULL)
    {
        printf("%d--> ", i);
        printf("%d \n", *(int *)current->content);
        current = current->next;
        i ++;
    }
    printf("\n");
}

void print_lst_str(t_list *head)
{
    t_list     *current;
    int       i;

    current = head;
    i = 0;
    while (current != NULL)
    {
        printf("%d--> ", i);
        printf("%s \n", (char *)current->content);
        current = current->next;
        i ++;
    }
    printf("\n");
}