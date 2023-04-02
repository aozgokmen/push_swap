/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_list2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocaaga <kkocaaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:24:22 by kkocaaga          #+#    #+#             */
/*   Updated: 2022/07/06 10:49:01 by kkocaaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	before_single_rotate(t_data *a, t_data *b, int *i_a, int *i_b)
{
	if (*i_a < (a->size / 2) && *i_b < (b->size / 2))
	{
		while (*i_a > 0 && *i_b > 0)
		{
			rotate_together(a, b, 0);
			*i_a -= 1;
			*i_b -= 1;
		}
	}
	else if (*i_a >= (a->size / 2) && *i_b >= (b->size / 2))
	{
		while (*i_a < a->size && *i_b < b->size && *i_a != 0 && *i_b != 0)
		{
			rev_rotate_together(a, b, 0);
			*i_a += 1;
			*i_b += 1;
		}
	}
}

void	send_a(t_data *a, t_data *b, int i_a, int i_b)
{
	before_single_rotate(a, b, &i_a, &i_b);
	if (i_a < (a->size / 2))
		while (i_a-- > 0)
			rotate(a, 0);
	else
		while (i_a++ < a->size)
			rev_rotate(a, 0);
	if (i_b < (b->size / 2))
		while (i_b-- > 0)
			rotate(b, 0);
	else
		while (i_b++ < b->size)
			rev_rotate(b, 0);
	push(b, a, 0);
}

void	final_move(t_data *a)
{
	int	i;

	i = 0;
	while (a->array[i] != 0)
		i++;
	if (i++ < a->size / 2)
		while (i--)
			rev_rotate(a, 0);
	else
		while (i++ < a->size)
			rotate(a, 0);
}

void	sort_the_list(t_data *a, t_data *b)
{
	int	i_a;
	int	i_b;

	send_b(a, b);
	while (b->size)
	{
		if (a->size <= 1)
			push(b, a, 0);
		find_sort_path(a, b, &i_a, &i_b);
		send_a(a, b, i_a, i_b);
	}
	final_move(a);
}
