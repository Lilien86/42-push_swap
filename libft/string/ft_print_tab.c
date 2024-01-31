/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:42:35 by lauger            #+#    #+#             */
/*   Updated: 2024/01/31 08:45:34 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_print_tab(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d: %d ", i, array[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}