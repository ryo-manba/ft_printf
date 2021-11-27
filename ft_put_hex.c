/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:11:57 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/11/27 22:06:05 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned long long n, t_info *info)
{
	if (n < 0)
		ft_putnbr_hex(-n, info);
	else if (n < 16)
		ft_put_hex(n, info);
	else
	{
		ft_putnbr_hex(n / 16, info);
		ft_putnbr_hex(n % 16, info);
	}
}

void	ft_put_hex(int n, t_info *info)
{
	char		c;
	const char	*small = "0123456789abcdef";
	const char	*large = "0123456789ABCDEF";

	if (info->specifier == SX)
		c = small[n];
	else if (info->specifier == LX)
		c = large[n];
	write(1, &c, 1);
	info->cnt++;
}
