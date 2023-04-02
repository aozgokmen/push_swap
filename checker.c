/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocaaga <kkocaaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:23:27 by kkocaaga          #+#    #+#             */
/*   Updated: 2022/07/06 10:47:04 by kkocaaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//bonus
void	check_list_checker(int *control, t_data *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->array[i] < a->array[i + 1])
			*control = 0;
		i++;
	}
	if (*control != 0)
		*control = 1;
}

void	rotate_func(char *s, t_data *a, t_data *b)
{
	if (s[0] == 'r' && s[1] == 'a')
		rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'b')
		rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
		rev_rotate(a, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
		rev_rotate(b, 1);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r')
		rev_rotate_together(a, b, 1);
	else if (s[0] == 'r' && s[1] == 'r')
		rotate_together(a, b, 1);
	else
		error_mes(a, b);
}

void	make_pros(t_data *a, t_data *b, char *s)
{
	if (s[0] == 's' && s[1] == 'a')
		swap(a, 1);
	else if (s[0] == 's' && s[1] == 'b')
		swap(b, 1);
	else if (s[0] == 's' && s[1] == 's')
		swap_together(a, b, 1);
	else if (s[0] == 'r')
		rotate_func(&s[0], a, b);
	else if (s[0] == 'p' && s[1] == 'a')
		push(b, a, 1);
	else if (s[0] == 'p' && s[1] == 'b')
		push(a, b, 1);
	else
		error_mes(a, b);
}

void	read_lines(t_data *a, t_data *b)
{
	char	*tmp;
	char	*buff;
	char	*test;

	buff = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			return ;
		test = tmp;
		while (*test)
		{
			if (*test == ' ')
				exit(1);
			test++;
		}
		make_pros(a, b, tmp);
	}
}

int	main(int ac, char **av)
{
	t_data	a;
	t_data	b;
	int		control;

	control = -1;
	a.type = 'a';
	b.type = 'b';
	if (ac >= 2)
		reading(av, &a, &b);
	else
		return (0);
	duplicate(&a, &b);
	read_lines(&a, &b);
	check_list_checker(&control, &a);
	if (control == 1 && !b.size)
		ft_printf("OK");
	else if (!control || b.size != 0)
		ft_printf("KO");
}
