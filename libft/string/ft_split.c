/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <lauger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:06:31 by marvin            #+#    #+#             */
/*   Updated: 2023/11/04 17:06:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_split_len(char const *str, char c);
static void	ft_split_fill(char const *str, char c, char **splitted);
static void	ft_count(int *counter, int *str_j, char const *str, char c);

char	**ft_split(char const *str, char c)
{
	int		len;
	char	**splitted;

	len = ft_split_len(str, c);
	splitted = malloc(sizeof(char *) * (len + 1));
	if (splitted == NULL)
		return (NULL);
	ft_split_fill(str, c, splitted);
	splitted[len] = 0;
	return (splitted);
}

static int	ft_split_len(char const *str, char c)
{
	int	i;
	int	j;
	int	tab_len;
	int	counter;

	tab_len = 0;
	i = -1;
	while (i == -1 || str[i])
	{
		if (i == -1 || str[i] == c)
		{
			counter = 0;
			j = i + 1;
			while (str[j] && str[j] != c)
			{
				counter++;
				j++;
				i++;
			}
			if (counter)
				tab_len += 1;
		}
		i++;
	}
	return (tab_len);
}

static void	ft_split_fill(char const *str, char c, char **splitted)
{
	int	str_i;
	int	str_j;
	int	tab_index;
	int	counter;

	tab_index = 0;
	str_i = -2;
	while (++str_i == -1 || str[str_i])
	{
		if (str_i == -1 || str[str_i] == c)
		{
			str_j = str_i + 1;
			ft_count(&counter, &str_j, str, c);
			if (counter)
			{
				splitted[tab_index] = malloc(sizeof(char) * (counter + 1));
				str_j = -1;
				while (++str_j < counter)
					splitted[tab_index][str_j] = str[str_i + 1 + str_j];
				splitted[tab_index][str_j] = '\0';
				tab_index++;
			}
			str_i += counter;
		}
	}
}

static void	ft_count(int *counter, int *str_j, char const *str, char c)
{
	*counter = 0;
	while (str[*str_j] && str[*str_j] != c)
	{
		*counter += 1;
		*str_j += 1;
	}
}

/*static size_t	ft_wcount(const char *str, char sep)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 1;
	if (!*str)
		return (0);
	if (str [i - 1] != sep)
		cnt++;
	while (str[i])
	{
		if (str[i] != sep && str[i - 1] == sep)
		{
			cnt++;
		}
		i++;
	}
	return (cnt);
}

static size_t	ft_cntletters(const char *s, size_t start, char sep)
{
	size_t	cnt;

	cnt = 0;
	while (s[start] && s[start] != sep)
	{
		start++;
		cnt++;
	}
	return (cnt);
}

static char	*ft_strmalloc(const char *s, size_t start, char sep, char	**tab)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = malloc (sizeof(char) * (ft_cntletters(s, start, sep) + 1));
	if (!p)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return (NULL);
	}
	while (s[start] && s[start] != sep)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return ((char *)p);
}

static void	ft_init_vars(size_t *start, size_t *i, size_t *j)
{
	*start = 0;
	*j = 0;
	*i = 0;
}

char	**ft_split(char const *s, char sep)
{
	char			**tab;
	size_t			start;
	size_t			j;
	size_t			i;

	if (s[0] == '\0' || s == NULL)
		return (NULL);
	ft_init_vars(&start, &i, &j);
	tab = malloc (sizeof(char *) * (ft_wcount(s, sep) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != sep && j < ft_wcount(s, sep))
		{
			start = i;
			tab[j] = ft_strmalloc(s, start, sep, tab);
			j++;
			while (s[i] && s[i] != sep)
				i++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}*/
