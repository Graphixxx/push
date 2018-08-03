/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:20:40 by swilson           #+#    #+#             */
/*   Updated: 2018/08/03 13:45:53 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	isit(t_node *l_a, t_node *l_b, int *c)
{
	t_node *temp;

	temp = l_a;
	*c = 3;
	///testing
	if (temp)
	{
		printf("-->%d\n", temp->nbr);
	}
	while (temp && !l_b)
	{
		if (temp->next == NULL)
		{
			*c = 2;
			return ;
		}
			if (temp->nbr < temp->next->nbr)
				temp = temp->next;
			else
				return ;
	}
}
