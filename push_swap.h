/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocaaga <kkocaaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:45:03 by kkocaaga          #+#    #+#             */
/*   Updated: 2022/07/06 10:47:56 by kkocaaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"

typedef struct s_data
{
	int		*array;
	int		size;
	char	type;
}	t_data;

void	swap(t_data *data, int control);
void	rotate(t_data *data, int control);
void	rev_rotate(t_data *data, int control);
void	push(t_data *data1, t_data *data2, int control);
void	sort_the_list(t_data *a, t_data *b);
void	indexing(t_data *a);
void	rotate_together(t_data *a, t_data *b, int control);
void	rev_rotate_together(t_data *a, t_data *b, int control);
void	swap_together(t_data *a, t_data *b, int control);
void	sort_smaller_list(t_data *a, t_data *b);
void	error_mes(t_data *a, t_data *b);
void	free_function(t_data *a, t_data *b);
void	send_b(t_data *a, t_data *b);
void	find_sort_path(t_data *a, t_data *b, int *i_a, int *i_b);
void	check_double(t_data *a, t_data *b);
void	check_listed(t_data *a, t_data *b);
void	reading(char **av, t_data *a, t_data *b);
void	check_listed_for_checker(t_data *a, t_data *b, int *control);
void	duplicate(t_data *a, t_data *b);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s1);
int		ft_atoii(char *s, t_data *a, t_data *b);
char	*ft_strjoinn(char const *s1, char const *s2);
#endif