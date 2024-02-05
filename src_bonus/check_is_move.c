/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 09:19:24 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 09:19:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int check_is_move(char *s)
{
    int length;

    length = strlen(s);
    if (length <= 3)
    {
        if ((ft_strcmp(s, "sa") == 0) || (ft_strcmp(s, "sb") == 0)
            || (ft_strcmp(s, "ra") == 0) || (ft_strcmp(s, "rb") == 0)
            || (ft_strcmp(s, "rr") == 0) || (ft_strcmp(s, "pa") == 0)
            || (ft_strcmp(s, "pb") == 0) || (ft_strcmp(s, "rra") == 0)
            || (ft_strcmp(s, "rrb") == 0) || (ft_strcmp(s, "rrr") == 0))
        {
            return 1;
        }
    }
    return 0;
}