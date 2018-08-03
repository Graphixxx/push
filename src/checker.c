/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 08:35:07 by swilson           #+#    #+#             */
/*   Updated: 2018/08/03 08:37:37 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	int c;
	int input[ac - 1];
	t_data *list;

	list = (t_data*)malloc(sizeof(t_data));
	list->head_a = NULL;
	list->head_b = NULL;
	list->size = ac - 1;
	if (ac > 1)
	{
		c = checkall(ac, av, input, &(list->size));
		if (c == 0)
			ft_putendl("Error");
		else if (c == 1)
		{
			//printin(input, ac - 1);
			setall(&list, input);
			sorting(&list, &c);
		}
		if (c == 2)
			ft_putendl("OK");
	}
	free(list);
	return (0);
}
