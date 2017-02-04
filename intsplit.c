/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcentaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:48:11 by jcentaur          #+#    #+#             */
/*   Updated: 2017/02/03 18:44:30 by jcentaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_countwords(char const *s)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (i == 0)
		{
			if (s[i] != ' ')
				words++;
		}
		else
		{
			if (s[i] != ' ' && s[i - 1] == ' ')
				words++;
		}
		i++;
	}
	return (words);
}

int			ft_len(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != ' ')
		i++;
	return (i);
}

int			*intsplit(char const *s, int *nb)
{
	int		*r;
	int		i;

	if (!s)
		return (NULL);
	*nb = ft_countwords(s);
	if (!(r = (int *)malloc(sizeof(*r) * *nb)))
		return (NULL);
	i = 0;
	while (i < *nb)
	{
		while (*s == ' ')
			s++;
		r[i] = atoi(s);
		s += ft_len(s);
		i++;
	}
	return (r);
}
