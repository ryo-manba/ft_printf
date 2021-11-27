/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:50:15 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/07 13:58:58 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_per(t_info *info)
{
	info->put_len = 1;
	if (info->field <= 1)
		info->field = 0;
	else
		info->field = info->field - 1;
	if (!info->flag[0] && !info->flag[1])
		put_flag(' ', info->field, info);
	if (!info->flag[0] && info->flag[1])
		put_flag('0', info->field, info);
	write(1, "%", 1);
	info->cnt++;
	if (info->flag[0])
		put_flag(' ', info->field, info);
}

void	ft_put_p1(va_list *ap, t_info *info)
{
	long long	n;

	info->specifier = SX;
	n = (long long)va_arg(*ap, void *);
	if (n == 0)
	{
		if (info->precision == -1)
			info->precision = 1;
		info->put_len = 2 + info->precision;
		if (info->field <= info->put_len)
			info->field = 0;
		info->field = info->field - info->put_len;
	}
	else
		ft_set(1, n, info);
	ft_put_p2(info, n);
}

void	ft_put_p2(t_info *info, long long n)
{
	if (!info->flag[0] && !info->flag[1])
		put_flag(' ', info->field, info);
	write(1, "0x", 2);
	info->cnt += 2;
	if (!info->flag[0] && info->flag[1])
		put_flag('0', info->precision + info->field, info);
	else
		put_flag('0', info->precision, info);
	if (n)
		ft_putnbr_hex(n, info);
	if (info->flag[0])
		put_flag(' ', info->field, info);
}
