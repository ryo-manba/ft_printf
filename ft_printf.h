/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuka < rmatsuka@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:22:10 by rmatsuka          #+#    #+#             */
/*   Updated: 2021/05/08 17:27:21 by rmatsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
typedef struct s_info
{
	int		flag[2];
	int		field;
	int		precision;
	int		specifier;
	int		put_len;
	int		cnt;
	char	*s;
}			t_info;

enum e_specifier
{
	C,
	S,
	P,
	D,
	I,
	U,
	SX,
	LX,
	PER
};

/* ft_printf */
int		ft_printf(const char *format, ...);
int		ft_print(const char **start, const char **format);
int		ft_parse(const char **start, const char **format, va_list *ap);
void	ft_init(t_info *info);
void	put_flag(char c, int len, t_info *info);

/* ft_printf_utils */
int		ft_strchr_i(char *s, char c);
int		s_to_num(const char **format, va_list *ap, t_info *info, int mode);
void	ft_set(long long n, unsigned long long un, t_info *info);
void	ft_put_exc(const char **start, const char **format, t_info *info);
void	ft_convert(const char **start, const char **format, va_list *ap,
			t_info *info);

/* ft_printf_utils2 */
int		ft_isdigit(int c);
int		get_digit(long long n, int type);
size_t	ft_strlen(char *s);

/* ft_put_s */
int		ft_set_s(va_list *ap, t_info *info);
int		str_is_null(t_info *info, int null_n);
void	ft_put_s(va_list *ap, t_info *info);
void	ft_put_c(va_list *ap, t_info *info);

/* ft_put_d */
void	ft_put_d(va_list *ap, t_info *info);
void	ft_set_d1(long long n, t_info *info);
void	ft_set_d2(long long n, t_info *info, int flags);
void	ft_putnbr(long long n, t_info *info);
void	ft_put_digit(int n, t_info *info);

/* ft_put_u */
void	ft_put_u(va_list *ap, t_info *info);
void	ft_set_u1(unsigned long long n, t_info *info);
void	ft_set_u2(unsigned long long n, t_info *info, int flags);
void	ft_putnbr_u(unsigned long long n, t_info *info);

/* ft_put_p */
void	ft_put_per(t_info *info);
void	ft_put_p1(va_list *ap, t_info *info);
void	ft_put_p2(t_info *info, long long n);

/* ft_put_hex */
void	ft_put_hex(int n, t_info *info);
void	ft_putnbr_hex(unsigned long long n, t_info *info);

#endif
