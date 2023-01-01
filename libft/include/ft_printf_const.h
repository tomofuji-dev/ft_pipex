/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_const.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/04 02:04:37 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONST_H
# define FT_PRINTF_CONST_H

# define FD_STDOUT		1
# define ERR_PRF		-1
# define CHR_CONV		'%'
# define CHR_SPACE		' '
# define CHR_ZERO		'0'
# define CHR_POINT		'.'
# define CHR_PRECISION	'.'
# define CHR_PLUS		'+'
# define CHR_MINUS		'-'
# define CHR_LEFT		'-'
# define CHR_ALT		'#'
# define CHR_REF		'*'
# define CHR_ORDER		'$'
# define CHR_EXP		'e'
# define CHR_EXP_A		'p'
# define CHRS_SPECIFY	"cspdiuxXo%fFeEgGaAnmCSDUO"
# define CHRS_FLAG		"-0# +123456789.*$hlLzjtq',;:_"
# define CHRS_SIGN		"-+ "
# define STR_EMPTY		""
# define STR_NULL		"(null)"
# define STR_SPACE		" "
# define STR_PLUS		"+"
# define STR_MINUS		"-"
# define STR_PAD_NUM	"0"
# define STR_PRE_X		"0x"
# define STR_PRE_O		"0"
# define STR_EXP_A		"p"
# define STR_INF		"inf"
# define STR_NAN		"nan"
# define NUM_NAN		0x7fff
# define NUM_INF		0x8000
# define NUM_NEG		0x8000
# define NUM_EXCESS		0x4002
# define NUM_EXCESS_A	0x03ff
# define NUM_SIG_A		0x000fffffffffffffLL
# define NUM_HIDDEN_A	0x0010000000000000LL
# define NUM_LLMAX10	1000000000000000000LL
# define LEN_SIG_A		13
# define LEN_SIG_LA		16
# define LEN_DEC_LDBL	26
# define EXP_LLMAX		18
# define PRECISION_F	6

#endif
