/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauger <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:45:11 by lauger            #+#    #+#             */
/*   Updated: 2024/02/01 15:05:36 by lauger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&((*lst)->next), del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
