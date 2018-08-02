/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:17:10 by swilson           #+#    #+#             */
/*   Updated: 2018/08/02 14:51:04 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	printlists(t_node *l_a, t_node *l_b)
{
	t_node *temp;
	t_node *temp1;

	temp = l_a;
	temp1 = l_b;
	while (temp || temp1)
	{
		if (temp)
		{
			printf("%d",temp->nbr);
			temp = temp->next;
		}
		printf("\t");
		if (temp1)
		{
			printf("%d",temp1->nbr);
			temp1 = temp1->next;
		}
		printf("\n");
	}
	printf("\n");
}

void	stack_push(t_node **l_a, t_node **l_b)
{
	t_node *temp;
	t_node *tnext;

	if (!(*l_a))
		return ;
	temp = (*l_a);
	tnext = temp->next;
	temp->next = (*l_b);
	if (*l_b)
		(*l_b)->prev = temp;
	(*l_b) = temp;
	*l_a = tnext;;
}
void	stack_swap(t_node **list)
{
	int n;

	if (!(*list) || !(*list)->next)
		return ;
	n = (*list)->nbr;
	(*list)->nbr = (*list)->next->nbr;
	(*list)->next->nbr = n;
}

////////  stack_rot(here)

void	sorting(t_data **data, int *c)
{
	t_node *l_a;
	t_node *l_b;
	int i;

	i = -1;
	l_a = (*data)->head_a;
	l_b = (*data)->head_b;
	stack_swap(&l_a);
	printlists(l_a, l_b);	
	stack_push(&l_a, &l_b);	
	printlists(l_a, l_b);	
	stack_swap(&l_a);
	printlists(l_a, l_b);	
	stack_push(&l_b, &l_a);	
	printlists(l_a, l_b);	
	*c = 2;
}
