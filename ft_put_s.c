/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:30:41 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/08 12:18:52 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_is_null(t_info *info, int null_n)
{
	if (!null_n)
	{
		info->s = "(null)";
		info->put_len = 6;
		if (info->put_len > info->precision)
			info->put_len = info->precision;
	}
	return (0);
}

int	ft_set_s(va_list *ap, t_info *info)
{
	int	n;
	int	s_len;

	n = 0;
	if (ap == NULL)
		return (str_is_null(info, 1));
	info->s = va_arg(*ap, char *);
	if (info->s == NULL)
		return (str_is_null(info, 0));
	s_len = ft_strlen(info->s);
	while (n < info->precision && n < s_len)
		n++;
	info->put_len = n;
	return (n);
}

void	ft_put_s(va_list *ap, t_info *info)
{
	if (info->precision == -1)
		info->precision = INT_MAX;
	ft_set_s(ap, info);
	if (info->field >= info->put_len)
		info->field = info->field - info->put_len;
	else
		info->field = 0;
	if (!info->flag[0])
	{
		if (info->flag[1])
			put_flag('0', info->field, info);
		else
			put_flag(' ', info->field, info);
	}
	write(1, info->s, info->put_len);
	info->cnt += info->put_len;
	if (info->flag[0])
		put_flag(' ', info->field, info);
}

void	ft_put_c(va_list *ap, t_info *info)
{
	char	c;

	c = (char)va_arg(*ap, int);
	info->put_len = 1;
	info->precision = 1;
	if (info->field <= info->put_len)
		info->field = 0;
	else
		info->field = info->field - info->put_len;
	if (!info->flag[0])
	{
		if (info->flag[1])
			put_flag('0', info->field, info);
		else
			put_flag(' ', info->field, info);
	}
	write(1, &c, 1);
	info->cnt++;
	if (info->flag[0])
	{
		if (info->flag[1])
			put_flag('0', info->field, info);
		else
			put_flag(' ', info->field, info);
	}
}
