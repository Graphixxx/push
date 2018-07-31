/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:37:19 by swilson           #+#    #+#             */
/*   Updated: 2018/07/31 13:12:06 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/push_swap.h"

int		checkmax_min(char *n)
{
	int nbr;
	char *temp;

	nbr = ft_atoi(n);
	temp = ft_itoa(nbr);
	if (ft_strequ(n, temp))
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

int		checkdup(char **av, char len, int start)
{
	int i;
	int j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (ft_strequ(av[i + start], av[j + start]))
				return (1);
		}
	}
	return (0);
}

int		checknu(int ac, char **av, int start, int *in)
{
	int i;
	int j;
	int len;

	i = -1;
	if (checkdup(av, ac - start, start))
		return (0);
	while (++i < ac - start)
	{
		j = -1;
		len = ft_strlen(av[i + start]);
		in[i] = ft_atoi(av[i + start]);
		if (!checkmax_min(av[i + start]))
			return (0);
	}
	return (1);
}

int		checkstr(char **av, int *in, int *len)
{
	int i;
	char **arr;

	i = -1;
	*len = ft_strlen(av[1]);
	while (++i < *len)
	{
		if (!ft_isdigit(av[1][i]) && av[1][i] != '-')
		{
			if (av[1][i] == ' ')
			{
				arr = ft_strlensplit(av[1], ' ', len);
				if (*len == 1)
					break ;
				return (checknu(*len, arr, 0, in));
			}
			return (0);
		}
	}
	if (!checkmax_min(av[1]))
		return (0);
	return (2);
}

int		checkall(int ac, char **av, int *in, int *len)
{
	if (ac > 2)
		return (checknu(ac, av, 1, in));
	else if (ac == 2)
		return (checkstr(av, in, len));
    return (0);
}
