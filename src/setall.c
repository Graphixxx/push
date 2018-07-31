/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:57:02 by swilson           #+#    #+#             */
/*   Updated: 2018/07/31 13:15:45 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

void	insertlist(t_data **data, int n)
{
	t_node	*i;
	t_node	*temp;

	i = (t_node*)malloc(sizeof(t_node));
	i->nbr = n;
	i->next = NULL;
	temp = (*data)->head_a;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = i;
		i->prev = temp;
		return ;
	}
	i->prev = NULL;
	(*data)->head_a = i;
}

void	printlist(t_node *list)
{
	t_node *temp;

	temp = list;
	if (!temp)
		return ;
	while (temp)
	{
		ft_putnbr(temp->nbr);
		ft_putchar('\n');
		temp = temp->next;
	}
}

int		setall(t_data **data, int *in)
{
	int i;
	i = -1;
	while (++i < (*data)->size)
		insertlist(data, in[i]);
	printlist((*data)->head_a);
	return (1);
}
