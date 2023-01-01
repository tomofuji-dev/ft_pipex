/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typedef.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/04 01:37:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPEDEF_H
# define FT_PRINTF_TYPEDEF_H

typedef struct s_conv
{
	int		type;
	int		flag;
	int		order;
	int		width;
	int		precision;
	ssize_t	len;
}	t_conv;

typedef struct s_len
{
	ssize_t	len;
	ssize_t	pos;
	ssize_t	ret_tmp;
}	t_len;

typedef struct s_fpos
{
	ssize_t	hi;
	ssize_t	pt;
	ssize_t	end;
}	t_fpos;

typedef struct s_flen
{
	ssize_t	org;
	ssize_t	sig;
	ssize_t	exp;
	ssize_t	pt;
}	t_flen;

typedef struct s_flen2
{
	ssize_t	new;
	ssize_t	pad;
	ssize_t	fill;
}	t_flen2;

typedef union u_ldbl
{
	long double			ldbl;
	unsigned long long	ll[2];
	unsigned short		sht[8];
}	t_ldbl;

typedef union u_dbl
{
	double				dbl;
	unsigned long long	ll;
	unsigned short		sht[4];
}	t_dbl;

typedef union u_wchr
{
	wchar_t			wchr;
	unsigned char	chr[4];
}	t_wchr;

#endif
