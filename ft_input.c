/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrandria <vrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:10:02 by vrandria          #+#    #+#             */
/*   Updated: 2024/03/28 10:47:03 by vrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
static size_t	ft_countword(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

int	*ft_insert_one(char *str)
{
	char **splited;
	int	i;
	int count_argc;
	int *value;

	count_argc = ft_countword(str, ' ');
	value = malloc(sizeof(int) * count_argc);
	if (!value)
		return (0);
	i = 0;
	splited = ft_split(str, ' ');
	while (!splited[i])
	{
		value[i] = ft_atoi(splited[i]);
		i++;
	}
	free(splited);
	return (value);
}