/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:20:07 by swilson           #+#    #+#             */
/*   Updated: 2018/08/03 11:34:19 by swilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "get_next_line.h"

typedef struct			s_node
{
	int					nbr;
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

typedef struct			s_data
{
	t_node				*head_a;
	t_node				*head_b;
	int					size;
}						t_data;

char					**ft_strlensplit(char const *s, char c, int *len);
int						checkall(int ac, char **av, int *in, int *len);
int						setall(t_data **list, int *in);
void					sorting(t_data **list, int *c);
void					isit(t_node *l_a, t_node *l_b, int *c);
#endif
