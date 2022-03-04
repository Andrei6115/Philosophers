/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:42:21 by calecia           #+#    #+#             */
/*   Updated: 2022/02/21 19:02:31 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

static void	for_atoi(const char	*str, int *check_sign, size_t *i)
{
	while (ft_isspace(str[*i]))
		i++;
	if (str[*i] == '+' || str[*i] == '-')
		if (str[(*i)++] == '-')
			*check_sign = 1;
}

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == 0 || str2[i] == 0)
			return (str1[i] - str2[i]);
		if (str1[i] == 0 || str2[i] == 0)
		{
			return (0);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t				i;
	int					check_sign;
	unsigned long long	res;

	i = 0;
	check_sign = 0;
	res = 0;
	for_atoi(str, &check_sign, &i);
	if (ft_strlen(str) > 19 && check_sign)
		return (0);
	if (ft_strlen(str) > 19)
		return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 - (str[i] - '0');
		i++;
	}
	if (!check_sign)
		return (-res);
	else
		return (res);
}
