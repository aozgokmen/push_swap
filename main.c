/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocaaga <kkocaaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:25:26 by kkocaaga          #+#    #+#             */
/*   Updated: 2022/06/29 15:26:36 by kkocaaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	a;
	t_data	b;

	a.type = 'a';
	b.type = 'b';
	if (ac >= 2)
		reading(av, &a, &b);
	else
		return (0);
	duplicate(&a, &b);
	indexing(&a);
	check_listed(&a, &b);
	if (a.size > 5)
		sort_the_list(&a, &b);
	else
		sort_smaller_list(&a, &b);
	free(a.array);
	free(b.array);
	return (0);
}
