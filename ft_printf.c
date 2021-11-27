/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka <rmatsuka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:20:00 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/08 11:58:28 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_info *info)
{
	info->flag[0] = 0;
	info->flag[1] = 0;
	info->field = -1;
	info->precision = -1;
	info->specifier = -1;
	info->put_len = -1;
	info->cnt = 0;
	info->s = NULL;
}

void	put_flag(char c, int len, t_info *info)
{
	if (len < 0)
		return ;
	while (len--)
	{
		write(1, &c, 1);
		info->cnt++;
	}
}

int	ft_put(const char **start, const char **format)
{
	while (**format && **format != '%')
		(*format)++;
	write(1, *start, *format - *start);
	return (*format - *start);
}

int	ft_parse(const char **start, const char **format, va_list *ap)
{
	int		i;
	t_info	info;

	(*format)++;
	ft_init(&info);
	i = ft_strchr_i("-0", **format);
	while (i >= 0)
	{
		info.flag[i] = 1;
		(*format)++;
		i = ft_strchr_i("-0", **format);
	}
	info.field = s_to_num(format, ap, &info, 0);
	if (**format == '.')
	{
		(*format)++;
		info.precision = s_to_num(format, ap, &info, 1);
	}
	info.specifier = ft_strchr_i("cspdiuxX%", **format);
	ft_convert(start, format, ap, &info);
	return (info.cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*start;
	int			printed_cnt;

	printed_cnt = 0;
	va_start(ap, format);
	if (format == NULL)
		printed_cnt = -1;
	while (*format)
	{
		start = format;
		if (*start == '%')
			printed_cnt += ft_parse(&start, &format, &ap);
		else
			printed_cnt += ft_put(&start, &format);
	}
	va_end(ap);
	return (printed_cnt);
}
