/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:19:32 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/06 22:10:43 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_digit(long long n, int type)
{
	int	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (type <= n)
	{
		n /= type;
		i++;
	}
	return (i);
}
