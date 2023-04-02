/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_numbers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocaaga <kkocaaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:25:17 by kkocaaga          #+#    #+#             */
/*   Updated: 2022/06/29 15:40:05 by kkocaaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*new_str;
	char	*f;
	int		i;
	int		j;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	f = (char *)malloc(len + 1);
	if (!f)
		return (0);
	j = 0;
	i = start;
	while (i < ft_strlen(s) && j < len)
		f[j++] = s[i++];
	f[j] = '\0';
	new_str = f;
	return (new_str);
}

int	ft_atoii(char *s, t_data *a, t_data *b)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg *= -1;
		i++;
	}
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			error_mes(a, b);
		res = (res * 10) + s[i++] - '0';
		if ((res * neg) > __INT_MAX__ || (res * neg) < -__INT_MAX__ - 1)
			error_mes(a, b);
	}
	return ((int)res * neg);
}

char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	i;

	i = ft_strlen(s1);
	str1 = (char *)malloc(sizeof(char) * i + 1);
	if (!str1)
		return (str1);
	str1[i] = 0;
	while (i--)
		str1[i] = s1[i];
	return (str1);
}

char	*ft_strjoinn(char const *s1, char const *s2)
{
	size_t	s1l;
	size_t	s2l;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + sizeof(char));
	if (!str)
		return (str);
	s1l = 0;
	s2l = 0;
	while (s1 && s1[s1l])
		str[s2l++] = s1[s1l++];
	s1l = 0;
	while (s2 && s2[s1l])
		str[s2l++] = s2[s1l++];
	str[s2l] = '\0';
	return (str);
}
