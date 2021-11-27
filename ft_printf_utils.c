/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:04:16 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/08 12:10:59 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr_i(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_convert(const char **start, const char **format,
			 va_list *ap, t_info *info)
{
	if (info->specifier == -1)
	{
		ft_put_exc(start, format, info);
		return ;
	}
	(*format)++;
	if (info->specifier == C)
		ft_put_c(ap, info);
	else if (info->specifier == S)
		ft_put_s(ap, info);
	else if (info->specifier == P)
		ft_put_p1(ap, info);
	else if (info->specifier == D || info->specifier == I)
		ft_put_d(ap, info);
	else if (U <= info->specifier && info->specifier <= LX)
		ft_put_u(ap, info);
	else if (info->specifier == PER)
		ft_put_per(info);
}

int	s_to_num(const char **format, va_list *ap, t_info *info, int is_pre)
{
	int	n;

	n = -1;
	if (**format == '*')
	{
		n = va_arg(*ap, int);
		if (n < 0 && !is_pre)
		{
			n = -n;
			info->flag[0] = 1;
		}
		else if (n < 0)
			n = -1;
		(*format)++;
	}
	else if (is_pre || ft_isdigit(**format))
	{
		n = 0;
		while (ft_isdigit(**format))
		{
			n = n * 10 + (**format - '0');
			(*format)++;
		}
	}
	return (n);
}

void	ft_set(long long n, unsigned long long un, t_info *info)
{
	int	flags;

	flags = 0;
	if (info->field != -1 && info->precision != -1)
		flags = 1;
	if (info->flag[1] && info->precision != -1)
		info->flag[1] = 0;
	if (U <= info->specifier && info->specifier <= LX)
	{
		if (info->specifier == U)
			info->put_len = get_digit(un, 10);
		else
			info->put_len = get_digit(un, 16);
		ft_set_u1(un, info);
		ft_set_u2(un, info, flags);
		if (n)
			info->field -= 2;
	}
	else if (info->specifier == D || info->specifier == I)
	{
		ft_set_d1(n, info);
		ft_set_d2(n, info, flags);
	}
}

void	ft_put_exc(const char **start, const char **format, t_info *info)
{
	info->field = 0;
	info->put_len = *format - *start;
	write(1, *start, info->put_len);
}
