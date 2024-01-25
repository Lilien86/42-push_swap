/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:26:20 by lauger            #+#    #+#             */
/*   Updated: 2024/01/25 11:23:12 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*void	ft_free_tab(void **arr, int size)
{
	int i;

	if (arr == NULL || *arr == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		free(arr[i]);
	}
	free(arr);
}*/

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
