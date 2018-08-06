/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:17:10 by swilson           #+#    #+#             */
/*   Updated: 2018/08/04 11:01:52 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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
	printf("_\t_\n");
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

void	stack_ss(t_node **l_a, t_node **l_b)
{
	stack_swap(l_a);
	stack_swap(l_b);
}


void	stack_rot(t_node **list)
{
	t_node *temp;
	t_node *last;

	if (!(*list) || !(*list)->next)
		return ;
	temp = *list;
	if (temp->next)
		*list = (*list)->next;
	else
	{
		free(*list);
		*list = NULL;
		return;
	}
	(*list)->prev = NULL;
	last = *list;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	temp->prev = last;
}

void	stack_rrot(t_node **list)
{
	t_node *temp;
	t_node *first;

	if (!(*list) || !(*list)->next)
		return ;
	temp = (*list);
	while (temp->next)
		temp = temp->next;
	temp->prev->next = NULL;
	first = *list;
	first->prev = temp;
	temp->next = first;
	temp->prev = NULL;
	*list = temp;
	temp = *list;
}

void	stack_rrr(t_node **l_a, t_node **l_b)
{
	stack_rrot(l_a);
	stack_rrot(l_b);
}

void	stack_rr(t_node **l_a, t_node **l_b)
{
	stack_rot(l_a);
	stack_rot(l_b);
}

void	sorting(t_data **data, int *c)
{
	t_node *l_a;
	t_node *l_b;
	char *line;
	int i;
	
	i = -1;
	l_a = (*data)->head_a;
	l_b = (*data)->head_b;
	while (get_next_line(1, &line))
	{
		if (ft_strequ(line, "sa"))
			stack_swap(&l_a);
		else if (ft_strequ(line, "sb"))
			stack_swap(&l_b);
		else if (ft_strequ(line, "ss"))
			stack_ss(&l_a, &l_b);
		else if (ft_strequ(line, "pb"))
			stack_push(&l_a, &l_b);	
		else if (ft_strequ(line, "pa"))
			stack_push(&l_b, &l_a);	
		else if (ft_strequ(line, "ra"))
			stack_rot(&l_a);
		else if (ft_strequ(line, "rb"))
			stack_rot(&l_b);
		else if (ft_strequ(line, "rr"))
			stack_rr(&l_a, &l_b);	
		else if (ft_strequ(line, "rra"))
			stack_rrot(&l_a);
		else if (ft_strequ(line, "rrb"))
			stack_rrot(&l_b);
		else if (ft_strequ(line, "rrr"))
			stack_rrr(&l_a, &l_b);
		else
		{
			break ;
		}
	}
	printlists(l_a, l_b);	
	isit(l_a, l_b, c);
}
