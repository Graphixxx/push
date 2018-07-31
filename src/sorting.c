/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:17:10 by swilson           #+#    #+#             */
/*   Updated: 2018/07/31 13:43:56 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting(t_data **data, int *c)
{
	t_node *l_a;
	t_node *l_b;
	int i;

	i = -1;
	l_a = (*data)->head_a;
	l_b = (*data)->head_b;
	while (++i < (*data)->size)
	{
		ft_putendl("ra");
	}
	
	*c = 2;
}
