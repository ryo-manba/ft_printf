/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:30:34 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/08 11:11:16 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_d(va_list *ap, t_info *info)
{
	long long	n;

	n = va_arg(*ap, int);
	ft_set(n, 0, info);
	if (!info->flag[0] && !info->flag[1])
		put_flag(' ', info->field, info);
	if (n < 0)
	{
		write(1, "-", 1);
		info->cnt++;
	}
	if (!info->flag[0] && info->flag[1])
	{
		if (n == 0 && info->field <= 0)
			put_flag('0', info->precision, info);
		else
			put_flag('0', (info->precision + info->field), info);
	}
	else
		put_flag('0', info->precision, info);
	if (n)
		ft_putnbr(n, info);
	if (info->flag[0])
		put_flag(' ', info->field, info);
}

void	ft_set_d1(long long n, t_info *info)
{
	info->put_len = get_digit(n, 10);
	if (n == 0 && info->precision != 0)
	{
		if (info->precision >= 1)
			info->precision = info->precision;
		else
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
}

void	ft_set_d2(long long n, t_info *info, int flags)
{
	info->field = info->field - info->put_len;
	if (flags)
	{
		if (n != 0)
			info->field -= info->precision;
		else
			info->field += info->put_len - info->precision;
	}
	if (n < 0)
		info->field -= 1;
}

void	ft_putnbr(long long n, t_info *info)
{
	if (n < 0)
		ft_putnbr(-n, info);
	else if (n < 10)
		ft_put_digit(n, info);
	else
	{
		ft_putnbr(n / 10, info);
		ft_putnbr(n % 10, info);
	}
}

void	ft_put_digit(int n, t_info *info)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
	info->cnt++;
}
