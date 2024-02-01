/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre-sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:28:59 by lauger            #+#    #+#             */
/*   Updated: 2024/02/01 10:19:38 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_to_array(t_list *head, int *size)
{
	int		count;
	t_list	*temp;
	int		*array;
	int		i;

	temp = head;
	count = *size;
	array = (int *)malloc(count * sizeof(int));
	if (array == NULL)
	{
		perror("Error\n allocated memories\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (temp != NULL)
	{
		array[i] = *((int *)(temp->content));
		temp = temp->next;
		i++;
	}
	*size = count;
	return (array);
}
