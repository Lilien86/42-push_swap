/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre-sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:28:59 by lauger            #+#    #+#             */
/*   Updated: 2024/01/25 11:02:37 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *list_to_array(t_list *head, int *size)
{
	int count = 0;
	t_list *temp = head;

	// Compter le nombre d'éléments dans la liste
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	// Allouer de la mémoire pour le tableau
	int *array = (int *)malloc(count * sizeof(int));
	if (array == NULL)
	{
		perror("Erreur d'allocation mémoire");
		exit(EXIT_FAILURE);
	}

	// Transcrire les éléments de la liste dans le tableau
	temp = head;
	int i = 0;
	while (temp != NULL)
	{
		// Affecter la valeur du contenu dans l'élément individuel
		array[i] = *((int *)(temp->content));

		temp = temp->next;
		i++;
	}
	*size = count;
	return array;
}