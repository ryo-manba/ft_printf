/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:30:38 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/08 12:13:55 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_u(va_list *ap, t_info *info)
{
	unsigned long long	n;

	n = (unsigned int)va_arg(*ap, int);
	ft_set(0, n, info);
	if (!info->flag[0] && !info->flag[1])
		put_flag(' ', info->field, info);
	if (!info->flag[0] && info->flag[1])
	{
		if (n == 0 && info->field <= 0)
			put_flag('0', info->precision, info);
		else
			put_flag('0', (info->precision + info->field), info);
	}
	else
		put_flag('0', info->precision, info);
	if (n && info->specifier == U)
		ft_putnbr_u(n, info);
	else if (n)
		ft_putnbr_hex(n, info);
	if (info->flag[0])
		put_flag(' ', info->field, info);
}

void	ft_putnbr_u(unsigned long long n, t_info *info)
{
	if (n < 10)
		ft_put_digit(n, info);
	else
	{
		ft_putnbr_u(n / 10, info);
		ft_putnbr_u(n % 10, info);
	}
}

void	ft_set_u1(unsigned long long n, t_info *info)
{
	if (n == 0 && info->precision == 0)
		info->precision = 0;
	else if (n == 0)
	{
		if (info->precision <= 0)
			info->precision = 1;
	}
	else
	{
		if (info->precision <= info->put_len)
		{
			if (n == 0 && info->precision)
				info->precision = 1;
			else
				info->precision = 0;
		}
		else
			info->precision = info->precision - info->put_len;
	}
	info->field = info->field - info->put_len;
}

void	ft_set_u2(unsigned long long n, t_info *info, int flags)
{
	if (flags)
	{
		if (n != 0)
			info->field -= info->precision;
		else
			info->field += info->put_len - info->precision;
	}
}
